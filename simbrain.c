/* Copyright (c) 2007-2017. The SimGrid Team. All rights reserved.          */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#include "simgrid/msg.h"
#include <math.h>
#include <unistd.h>

XBT_LOG_NEW_DEFAULT_CATEGORY(SimBrain, "Messages specific for this msg example");

static int output(int argc, char *argv[])
{
  xbt_assert(argc==2, "The output function one argument from the XML deployment file");
  

  double b0 = 1; 
  double mp = 1;
  double p;
  
  while(1)
  {
  	XBT_INFO("Out -> %s", argv[1]);
    xbt_assert(MSG_host_by_name(argv[1]) != NULL, "Unknown host %s. Stopping Now! ", argv[1]);
	p = 1-exp(-b0*mp);	
	msg_task_t out_task = MSG_task_create("output", 0.0, 1, NULL);
	out_task->data = xbt_new(double, 1);
	*(double *) out_task->data = p;
	MSG_task_send(out_task, argv[1]);
  
	sleep(1);
  }
 
  return 0;
}

static int input(int argc, char *argv[])
{
  double p = 0;

  while(1)
  {
	msg_task_t in_task = NULL;
	int a = MSG_task_receive(&in_task, MSG_host_get_name(MSG_host_self()));
	xbt_assert(a == MSG_OK, "Unexpected behavior");

	p = p + *((double *) (in_task->data));

  XBT_INFO("Task received : %s", in_task->name);
  xbt_free(in_task->data);
  MSG_task_destroy(in_task);

	sleep(1);
  }

  return 0;
}

int main(int argc, char *argv[])
{
  MSG_init(&argc, argv);

  xbt_assert(argc > 2, "Usage: %s platform_file deployment_file\n"
             "\tExample: %s ../../platforms/small_platform.xml app-pingpong_d.xml\n", argv[0], argv[0]);

  MSG_create_environment(argv[1]);          /* - Load the platform description */

  MSG_function_register("output", output);
  MSG_function_register("input", input);    /* - Register the functions to be executed by the processes */

  MSG_launch_application(argv[2]);          /* - Deploy the application */

  msg_error_t res = MSG_main();             /* - Run the simulation */

  return res!=MSG_OK;
}
