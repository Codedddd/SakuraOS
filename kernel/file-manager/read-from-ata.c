#include <stdint.h>

// ATA primary I/O ports (ATA = Advanced Technology Attachment)

#define ATA_PRIMARY_DATA 
#define ATA_ERROR_DATA

// Port I/O functions via inline-assembly (x86_64)

static inline uint8_t inb(uint16_t portAddr) {

    uint16_t result; // Declare the variable "result" with a type of unsigned 16 bit integer.
    __asm volatile("inb %1 , %0" : "=a"(result) : "dN"(portAddr));
    return result;

    // "inb %1 %0"    : Assembly instruction to read from port 1 and return the result in bytes.
    // "=a"(result)   : Tells the compiler to store the result in the AL GPR (lower half of the EAX and RAX registers) then stored in the "result" variable.
    // "dN"(portAddr) : Tells the compiler that the port that the data was accessed through should be stored in the DX register.
}

static inline void outb(uint16_t portAddr , uint8_t data) {

    __asm volatile("outb %1 , %0" : : "dN"(portAddr) , "a"(data));
}

static inline uint16_t inw(uint16_t portAddr) {

    uint16_t result;
    __asm volatile("inw %1 , %0" : "=a"(result) : "dN"(portAddr));
    return result;
}

static inline void outw(uint16_t portAddr , uint16_t data) {

    __asm volatile("outw %1 , %0" : : "dN"(portAddr) , "a"(data));
}

// Redundant ATA I/O operations but they are more of a fail-safe (these can support more bps in I/O ops than Windows & Linux wtf lmao).

static inline uint32_t inl(uint32_t portAddr) {

    uint32_t result;
    __asm volatile("inl %1 , %0" : "=a"(result) : "dN"(portAddr));
    return result;
}

static inline void outl(uint32_t portAddr , uint32_t data) {

    __asm volatile("outl %1 , %0" : : "dN"(portAddr) , "a"(data));
}