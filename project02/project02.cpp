#include "project02.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef unsigned char BYTE;  


	/*                    
		Variable declaration for 
		calculating execution cycles.
	*/
int set_cycle=0;
int add_cycle=0;
int subtract_cycle=0;
int multiply_cycle=0;
int division_cycle=0;				
int actual_size;
int current;
int last;


double inputSize(FILE *file)
{
	char *stream;
	current = ftell(file);
	fseek(file, 0, 2);
	last = ftell(file);
	fseek(file, current, 0);
	return last;
}

int main(int argc, char *argv[]){
	//Implementation of fetch stage
    	BYTE *fileBuf;		
	FILE *file =fopen(argv[1], "rb");		
	int actual_size = inputSize(file);
	fileBuf = new BYTE[actual_size];

	//Implementation of decode stage
	//cout<<"Actual File Size (in bytes):"<<actual_size;
        request_done =-1;
	fread(fileBuf, actual_size, 1, file);
	  
	//part of driver-code      
	 Simple_Pipe simple_pipe;
    	for(int i = 0; i < REG_COUNT; i++){
       	 simple_pipe.registers[i] = 0;
   	 }
	//Implementation of execution stage	
	int opc;
	int stop;
	int left;
	int right;
	
	for (int i=0;i<=600;i+=4){
        	request_done=request_done+1;	

		/*		
			Typecasting for converting 
			the actual instructions
		*/ 	

		opc = (int)fileBuf[i+3];
		stop = (int)fileBuf[i+2];
		left = (int)fileBuf[i+1];
		right = (int)fileBuf[i+0];
	

			/*
				Converted opcode for the binary to decimal.
				00->set->0
				10->add->16
				11->add->17
				20->sub->32
				21->sub->33
				30->mul->48
				31->mul->49
				40->div->64
				41->div->65

			*/	

			if(opc==0)
				{
					//Mnemonic - set instruction
					simple_pipe.registers[stop] = left;
					set_cycle=set_cycle+1;
					//cout<<opc;
				}
			
			if(opc==16)
				{
					//Mnemonic - add instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] + simple_pipe.registers[right];
					add_cycle=add_cycle+1;
				 
				}
	
			else if(opc ==17)
				{
						
					//Mnemonic - add instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] + right;
					add_cycle=add_cycle+1;
				}

			else if(opc ==32)
				{
					//Mnemonic - sub instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] - simple_pipe.registers[right];
					subtract_cycle=subtract_cycle+1;
					
				}

			else if(opc ==33)
				{
					//Mnemonic - sub instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] - right;
					subtract_cycle=subtract_cycle+1;
				}
			else if(opc ==48)
				{
					//Mnemonic - multiply instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] * simple_pipe.registers[right];
					multiply_cycle=multiply_cycle+2;
				}
			else if(opc ==49)
				{
					
					//Mnemonic - multiply instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] * right;
					multiply_cycle=multiply_cycle+2;
				}
			else if(opc ==64)
				{
					//Mnemonic - division instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] / simple_pipe.registers[right];
					division_cycle=division_cycle+4;
					//cout<<division_cycle;
				}

			else if(opc ==65)
				{	
					//Mnemonic - division instruction
					simple_pipe.registers[stop] = simple_pipe.registers[left] / right;
					division_cycle=division_cycle+4;
				}

			}


    	execution_time =set_cycle+add_cycle+subtract_cycle+multiply_cycle+division_cycle+1;  //calculating the execution time 	 	
    	simple_pipe.print_regs();
    	std::cout << "Total execution cycles: " << execution_time << std::endl;
    	std::cout << "\nIPC: " << (request_done/(double)execution_time) << std::endl << std::endl;
	

	delete[] fileBuf; //deleting created file buffer
    	fclose(file);	  //closing file attribute
    	return 0;
	}



void Simple_Pipe::print_regs(){
    printf("\nRegisters: \n");
    std::cout << "----------------------------------------" << std::endl;
    for(int i = 0; i < REG_COUNT; i+=2){
        std::string regl("R");
        regl.append(std::to_string(i));
        regl.append(": ");

        std::string regr("R");
        regr.append(std::to_string(i+1));
        regr.append(": ");
        if(i < 15){
            std::cout << "  " << std::setiosflags(std::ios::left) 
            << std::setw(5) << regl  << std::setw(10) << registers[i] << " |   " 
            << std::setw(5) << regr << std::setw(10) << registers[i+1] << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }else{
            std::cout << "  " << std::setiosflags(std::ios::left) 
            << std::setw(5) << regl << std::setw(10) << registers[i] << " |   " << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }  
    printf("\n");
}
