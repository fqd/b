#include <stdio.h>

static unsigned int eax;
static unsigned int ebx;
static unsigned int edx;
static unsigned int ecx;

char str[256];


int main()
{
	/// 0 - get vendor ID
	__asm__("xorq %rax, %rax"); 
	__asm__("cpuid");
	__asm__("movl %ebx, ebx");
	__asm__("movl %edx, edx");
	__asm__("movl %ecx, ecx");
	*((unsigned int*)&str) = ebx;
	*((unsigned int*)&str[4]) = edx;
	*((unsigned int*)&str[8]) = ecx;
	printf("vendor ID:\t%s\n", str);


	/// 1 - feature bits
	__asm__("movq $1, %rax");
	__asm__("cpuid");
	__asm__("movl %eax, eax"); // signature of a CPU
	__asm__("movl %edx, edx"); // feature flags
	__asm__("movl %ecx, ecx"); // feature flags
	__asm__("movl %ebx, ebx"); // additional feature
	
	printf("eax:\t%X\n", eax);
	printf("stepping:\t%d\n", (eax & 15));
	printf("model:\t%d\n", ((eax >> 4) & 15));
	printf("family:\t%d\n", ((eax >> 8) & 15));
	printf("processor type:\t%d\n", ((eax >> 12) & 3));
	printf("extended model:\t%d\n", ((eax >> 14) & 15));
	printf("extended family:\t%d\n", ((eax >> 18) & 0xFF));

	printf("FPU:\t%s\n", (edx & 1) ? "YES" : "NO");
	printf("VME:\t%s\n", ((edx >> 1) & 1) ? "YES" : "NO");
	printf("DE:\t%s\n",  ((edx >> 2) & 1) ? "YES" : "NO");
	printf("PSE:\t%s\n", ((edx >> 3) & 1) ? "YES" : "NO");
	printf("TSC:\t%s\n", ((edx >> 4) & 1) ? "YES" : "NO");
	printf("MSR:\t%s\n", ((edx >> 5) & 1) ? "YES" : "NO");
	printf("PAE:\t%s\n", ((edx >> 6) & 1) ? "YES" : "NO");
	printf("MCE:\t%s\n", ((edx >> 7) & 1) ? "YES" : "NO");
	printf("CX8:\t%s\n", ((edx >> 8) & 1) ? "YES" : "NO");
	printf("APIC:\t%s\n", ((edx >> 9) & 1) ? "YES" : "NO");
	// 10 - reserved
	printf("SEP:\t%s\n",    ((edx >> 11) & 1) ? "YES" : "NO");
	printf("MTRR:\t%s\n",   ((edx >> 12) & 1) ? "YES" : "NO");
	printf("PGE:\t%s\n",    ((edx >> 13) & 1) ? "YES" : "NO");
	printf("MCA:\t%s\n",    ((edx >> 14) & 1) ? "YES" : "NO");
	printf("CMOV:\t%s\n",   ((edx >> 15) & 1) ? "YES" : "NO");
	printf("PAT:\t%s\n",    ((edx >> 16) & 1) ? "YES" : "NO");
	printf("PSE-36:\t%s\n", ((edx >> 17) & 1) ? "YES" : "NO");
	printf("PSN:\t%s\n",    ((edx >> 18) & 1) ? "YES" : "NO");
	printf("CLFSH:\t%s\n",  ((edx >> 19) & 1) ? "YES" : "NO");
	// 20 - reserved
	printf("DS:\t%s\n",   ((edx >> 21) & 1) ? "YES" : "NO");
	printf("ACPI:\t%s\n", ((edx >> 22) & 1) ? "YES" : "NO");
	printf("MMX:\t%s\n",  ((edx >> 23) & 1) ? "YES" : "NO");
	printf("FXSR:\t%s\n", ((edx >> 24) & 1) ? "YES" : "NO");
	printf("SSE:\t%s\n",  ((edx >> 25) & 1) ? "YES" : "NO");
	printf("SSE2:\t%s\n", ((edx >> 26) & 1) ? "YES" : "NO");
	printf("SS:\t%s\n",   ((edx >> 27) & 1) ? "YES" : "NO");
	printf("HTT:\t%s\n",  ((edx >> 28) & 1) ? "YES" : "NO");
	printf("TM:\t%s\n",   ((edx >> 29) & 1) ? "YES" : "NO");
	printf("IA64:\t%s\n", ((edx >> 30) & 1) ? "YES" : "NO");
	printf("PBE:\t%s\n",  ((edx >> 31) & 1) ? "YES" : "NO");


	printf("SSE3:\t%s\n",             (ecx & 1) ? "YES" : "NO");
	printf("PCLMULQDQ:\t%s\n", ((ecx >> 1) & 1) ? "YES" : "NO");
	printf("DTES64:\t%s\n",    ((ecx >> 2) & 1) ? "YES" : "NO");
	printf("MONITOR:\t%s\n",   ((ecx >> 3) & 1) ? "YES" : "NO");
	printf("DS-CPL:\t%s\n",    ((ecx >> 4) & 1) ? "YES" : "NO");
	printf("VMX:\t%s\n",       ((ecx >> 5) & 1) ? "YES" : "NO");
	printf("SMX:\t%s\n",       ((ecx >> 6) & 1) ? "YES" : "NO");
	printf("EST:\t%s\n",       ((ecx >> 7) & 1) ? "YES" : "NO");
	printf("TM2:\t%s\n",       ((ecx >> 8) & 1) ? "YES" : "NO");
	printf("SSSE3:\t%s\n",     ((ecx >> 9) & 1) ? "YES" : "NO");
	printf("CNXT-ID:\t%s\n",  ((ecx >> 10) & 1) ? "YES" : "NO");
	printf("SDBG:\t%s\n",     ((ecx >> 11) & 1) ? "YES" : "NO");
	printf("FMA:\t%s\n",      ((ecx >> 12) & 1) ? "YES" : "NO");
	printf("CX16:\t%s\n",     ((ecx >> 13) & 1) ? "YES" : "NO");
	printf("XTPR:\t%s\n",     ((ecx >> 14) & 1) ? "YES" : "NO");
	printf("PDCM:\t%s\n",     ((ecx >> 15) & 1) ? "YES" : "NO");
	// 16 - reserved
	printf("PCID:\t%s\n",     ((ecx >> 17) & 1) ? "YES" : "NO");
	printf("DCA:\t%s\n",      ((ecx >> 18) & 1) ? "YES" : "NO");
	printf("SSE4.1:\t%s\n",   ((ecx >> 19) & 1) ? "YES" : "NO");
	printf("SSE4.2:\t%s\n",   ((ecx >> 20) & 1) ? "YES" : "NO");
	printf("X2APIC:\t%s\n",   ((ecx >> 21) & 1) ? "YES" : "NO");
	printf("MOVBE:\t%s\n",    ((ecx >> 22) & 1) ? "YES" : "NO");
	printf("POPCNT:\t%s\n",   ((ecx >> 23) & 1) ? "YES" : "NO");
	printf("TSC-DEADLINE:\t%s\n",     ((ecx >> 24) & 1) ? "YES" : "NO");
	printf("AES:\t%s\n",     ((ecx >> 25) & 1) ? "YES" : "NO");
	printf("XSAVE:\t%s\n",   ((ecx >> 26) & 1) ? "YES" : "NO");
	printf("OSXSAVE:\t%s\n", ((ecx >> 27) & 1) ? "YES" : "NO");
	printf("AVX:\t%s\n",     ((ecx >> 28) & 1) ? "YES" : "NO");
	printf("F16C:\t%s\n",    ((ecx >> 29) & 1) ? "YES" : "NO");
	printf("RDRND:\t%s\n",   ((ecx >> 30) & 1) ? "YES" : "NO");
	printf("HYPERVISOR:\t%s\n",     ((ecx >> 31) & 1) ? "YES" : "NO");

	return 0;
}
