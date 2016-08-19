#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[])
{	

std::string GERMLINE="-germline9.1";
std::string FISHR = "-ErrorFinder25.0";
std::stringstream ss2("");
std::string s1 = "-germline9.1";
std::string s2 = "-ErrorFinder25.0";
std::string s1_data =" ";
std::string s2_data =" ";
bool glflag =  false;
bool fishrflag =  false;

/*Check for errors*/
if (argc<3)
	{
		std::cout<<"Error: No input provided\n";
		std::cout<<"The input should be of the form \n -germline9.1 <parameters> \nand \n -ErrorFinder25.0 <parameters> "<<std::endl;
		exit(0);
	}
if (argv[1] == s1)
	{
		glflag =  true;
	}
else if (argv[1] == s2)
	{
		fishrflag =  true;
	}
else
	{
		std::cout<<"Error: Wrong binary targeted"<<std::endl;
		exit(0);
	}
std::string line ="";
std::string low_ram = "-low_ram";
std::stringstream ss("");
bool flag=false;
//char** tokens;

//*tokens = strtok(*tokens, " ");
//execvp(tokens[0], tokens);

//std::cout<<argc <<std::endl;
ss.clear();

	for (int i = 2; i < argc; i++)
		{
			if (glflag == true)
				{

				if (s2 == argv[i])
					{
						glflag = false;
						fishrflag = true;
					}

				if (	(argv[i]!= s1) && (argv[i]!=s2))
					{
						s1_data+= argv[i];
						s1_data += " ";
					}

				}
			if (fishrflag == true)
				{
					if (!strcmp(low_ram.c_str(),argv[i]))
						{
							//-low_ram flag is passed
							flag = true;
							continue;
						}

					if (s2 == argv[i])
						{
							glflag = false;
							fishrflag = true;
						}
					if (	(argv[i]!= s1) && (argv[i]!=s2))
						{
							s2_data+= argv[i];
							s2_data+= " ";
						}

					if (s2 == argv[i])
						{
							glflag = false;
							fishrflag = true;
						}
				}

			//std::cout<<argv[i]<<std::endl;
		}


system(("./germline9.1"+ s1_data	).c_str());
if (flag == true)
	{
		//flag = system(("/work/KellerLab/opt/bin/fishr_low_ram7.0 " +  ss.str()).c_str());
		//flag = system(	("/work/KellerLab/opt/bin/fishr_low_ram7.0 " +  s2_data).c_str());
		flag = system(	("./fishr_low_ram7.0 " +  s2_data).c_str());

	}
else if(flag == false)
	{
		//flag = system(("/work/KellerLab/opt/bin/ErrorFinder25.0 " + ss.str()).c_str());
		//flag = system(("/work/KellerLab/opt/bin/ErrorFinder25.0 " + s2_data).c_str());
		flag = system(("./ErrorFinder25.0 " + s2_data).c_str());
	}

else
	{

	}
	return 0;
}