# SimBrain
A SimGrid-based simulator of protein spread in the brain
##### Simulation of misfolded protein propagation in the brain as a distributed computing system

We model the brain as a distributed system where computing nodes represent brain regions
and network links transport misfolded proteins (MPs). Nodes may produce, clear, and store MPs
using similar processes as described in ​ (Iturria-Medina et al. 2014)​ . We leverage the SimGrid
(Casanova et al. 2013)​ toolkit, the most advanced simulator for distributed systems, to simulate
such a system. We compare our discrete-event simulation to the simulator in ( ​ Iturria-Medina et
al. 2014)​.

### Prerequisites

* [SimGrid 3.17](http://simgrid.gforge.inria.fr)
* C

### Instalation

* Under Debian, Ubuntu and similar systems, you can simply get the latest version of SimGrid from your distribution. For example, simply type the following in a terminal (as root):

`apt-get install simgrid`

* You could also use the SimGrid docker container and get your code into the container, by typing the following in a terminal:

`sudo docker run --rm -it -v /path/to/local/directory:/SimBrain path/to/container/directory`

  * example: sudo docker run --rm -it -v /home/masoud/Desktop/SimBrain:/SimBrain bigdatalabteam/simgriddocker /bin/bash

### Usage

Type the following in a terminal:

1. List files (ls)
2. Change directory to (cd) SimBrain
3. List files. Then, you will see the following files inside of it: `simbrain.c  simbrain.xml  simbrain_d.xml`
4. `LD_LIBRARY_PATH=/simgrid/lib`
5. `export LD_LIBRARY_PATH`
6. Compile the C code using the following:

`gcc simbrain.c -I/simgrid/include -L/simgrid/lib -lsimgrid -lm -o simbrain`

7. List files. You will see the binary file has been built: `simbrain  simbrain.c  simbrain.xml  simbrain_d.xml`
8. Run the binary file using the following:

`./simbrain ./simbrain.xml ./simbrain_d.xml`

### License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](https://github.com/ma5oud180/SimBrain/blob/master/LICENSE) file for details.	
