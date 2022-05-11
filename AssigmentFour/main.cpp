#include "Metropolis.h"

/// checks the amount of arguments
/// \param amount
void checkArgc(int amount)
{
  if(amount!=3)
    error()
}

/// checks the first argument whether its valid
/// also sends each row to analyse and insert into the "city sketch" ( double graph )
/// \param checkMe given argument
/// \param size size to be checked by
/// \return
double** checkArgvOne(char **checkMe,unsigned int& size)
{
  ifstream file;
  string line;
  double **graph;

  file.open(checkMe[1]);
  getline(file,line);

  if(!isdigit(line[0]))
    error()

  size = atoi(&line[0]);

  graph = new double*[size];

  for(unsigned int i=0;i<size;i++)
  {
    graph[i] = new double[size];
    getline(file,line);
    Metropolis ::checkArgsMap(line,size,i,graph);
  }

  file.close();
  return graph;
}

/// after metropolitan instance has been made, this function will insert the cars into the instance
/// by given second argument.
/// also checks whether second argument is valid by size
/// \param argv second argument
/// \param size size
/// \param met metropolitan instance
void checkArgvTwo(char** argv,int size,Metropolis& met)
{
  ifstream file;
  string line;
  int count = 0;

  file.open(argv[2]);

  while(getline(file,line))
  {
    count++;
    if(count > size)
      error()
    Metropolis::carsSetup(line.substr(2),count-1,met);
  }
  if(count!= size)
    error()
  file.close();
}

/// starts the simulation by checking arguments, creating the metropolitan instance and running it.
///
/// *Important Note* if any of the arguments is in valid, an error message will occur and the system will exit!.
///
/// \param argc
/// \param argv
/// \param size
/// \param graph
void go(int argc,char**argv,unsigned int&size,double**graph)
{
  checkArgc(argc);
  Metropolis met(graph,size);

  checkArgvTwo(argv,size,met);

  met.iteration();

  for(unsigned int i = 0;i < size;i++)
    delete []graph[i];
  delete []graph;
}

int main(int argc,char **argv) {
  double ** graph;
  unsigned int size = 0;
  graph = checkArgvOne(argv,size);
  go(argc,argv,size,graph);
  return 0;
}
