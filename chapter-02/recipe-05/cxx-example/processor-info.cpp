#include "config.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    cout << "Number of logical cores: " << NUMBER_OF_LOGICAL_CORES << endl;
    cout << "Number of physical cores: " << NUMBER_OF_PHYSICAL_CORES << endl;

    cout << "Total virtual memory in megabytes: " << TOTAL_VIRTUAL_MEMORY << endl;
    cout << "Available virtual memory in megabytes: " << AVAILABLE_VIRTUAL_MEMORY << endl;
    cout << "Total physical memory in megabytes: " << TOTAL_PHYSICAL_MEMORY << endl;
    cout << "Available physical memory in megabytes: " << AVAILABLE_PHYSICAL_MEMORY << endl;

    cout << "Processor is 64bit: " << IS_64BIT << endl;
    cout << "Processor has floating point unit: " << HAS_FPU << endl;
    cout << "Processor supports MMX instructions: " << HAS_MMX << endl;
    cout << "Processor supports Ext. MMX instructions: " << HAS_MMX_PLUS << endl;
    cout << "Processor supports SSE instructions: " << HAS_SSE << endl;
    cout << "Processor supports SSE2 instructions: " << HAS_SSE2 << endl;
    cout << "Processor supports SSE FP instructions: " << HAS_SSE_FP << endl;
    cout << "Processor supports SSE MMX instructions: " << HAS_SSE_MMX << endl;
    cout << "Processor supports 3DNow instructions: " << HAS_AMD_3DNOW << endl;
    cout << "Processor supports 3DNow+ instructions: " << HAS_AMD_3DNOW_PLUS << endl;
    cout << "IA64 processor emulating x86: " << HAS_IA64 << endl;

    cout << "OS name: " << OS_NAME << endl;
    cout << "OS sub-type: " << OS_RELEASE << endl;
    cout << "OS build ID: " << OS_VERSION << endl;
    cout << "OS platform: " << OS_PLATFORM << endl;

    return EXIT_SUCCESS;
}