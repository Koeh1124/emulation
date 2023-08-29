#include <iostream>

struct Chip_8
{
    public:

        /// @brief Allows us to execute a program on the cpu
        /// @param cycles 
        /// @param start_address 
        void execute(int cycles, short start_address){
            // reset the cpu
            this -> reset();

            while(cycles){
                

                // reduce cycles by one once we have ran the instruction
                cycles --;
                PC ++;
                if (DT){
                    DT--;
                }
                if (ST){
                    ST--;
                }
            };

            return;
        };

        /// @brief used to input values to the cpu, allowing for user interaction
        /// @param new_input 
        void set_input(unsigned char new_input){
            input = new_input;
        };

   private:

        bool started = false; // tells us weather or not we need to run the start up for the cpu
    
        int PC; // program counter
        int DT; // Delay timer
        int ST; // Sound timer


        unsigned char instruction; // current instruction

        unsigned char v1, v2, v3, v4, v5, v6, v7, v8, v9, vA, vB, vC, vD, vE, vF; // main register
        
        unsigned short vI; // register used to store memory addresses

        unsigned char input; // this is used for input to the cpu

        unsigned char memory [4096]; // memory of the cpu

        // method used to reset the cpu
        void reset(){
            // reset program counter
            PC = 0;

            // reset all main registers
            v1,v2,v3,v4,v5,v6,v7,v8,v9,vA,vB,vC,vD,vE,vF = 0;
            
            // reset address register
            vI = 0;
        };

        // function to be ran when the cpu is first started
        void start(){
            unsigned char interpreter_memory [512] = {
                //sprites 0-F
                
                // 0
                0xF0,0x90,0x90,0x90,0xF0,
                // 1
                0x20,0x60,0x20,0x20,0x70,
                // 2
                0xF0,0x10,0xF0,0x80,0xF0,
                // 3
                0xF0,0x10,0xF0,0x10,0xF0,
                // 4
                0x90,0x90,0xF0,0x10,0x10,
                // 5
                0xF0,0x80,0xF0,0x10,0xF0,
                // 6
                0xF0,0x90,0xF0,0x90,0xF0,
                // 7
                0xF0,0x10,0x20,0x40,0x40,
                // 8
                0xF0,0x90,0xF0,0x90,0xF0,
                // 9
                0xF0,0x90,0xF0,0x10,0xF0,
                // A
                0xF0,0x90,0xF0,0x90,0x90,
                // B
                0xE0,0x90,0xE0,0x90,0xE0,
                // C
                0xF0,0x80,0x80,0x80,0xF0,
                // D
                0xE0,0x90,0x90,0x90,0xE0,
                // E
                0xF0,0x80,0x80,0x80,0xF0,
                // F
                0xF0,0x80,0xF0,0x80,0x80
            };

            // load interpreter memory

        }
};


int main(int argc, char const *argv[])
{
    using namespace std;
    Chip_8 cpu;
    cpu.execute(12);
    cout << "ran";
    return 0;
}
