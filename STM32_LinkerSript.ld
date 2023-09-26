/**
 ******************************************************************************
 * @file      STM32_LinkerScript.ld
 * @author    Adel Hani Saeed
 * @brief     Linker script for STM32F401CCFx Device from STM32F4 series
 *               FLASH Size     256Kbytes FLASH
 *               RAM Size       64Kbytes RAM
 *
 *            Set heap size, stack size and stack location according
 *            to application requirements.
 *
 *            Set memory bank area and size if external memory is used
 ******************************************************************************/


/* Entry Point */
ENTRY(Reset_Handler)



/* Memories definition */
MEMORY
{
    FLASH(rx): ORIGIN= 0x08000000 , LENGTH= 256K
    SRAM(rwx): ORIGIN= 0x20000000 , LENGTH= 64K
}


/* Sections */
SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        _etext = . ;                  /*symbol have a last address in the .text output section*/
    }>FLASH                           /*>FLASH AT> FLASH (Vitual and load addresses are the same location in FLASH Memory)*/

    .data :
    {
        _sdata = . ;                  /*symbol have a first address in the .data output section*/
        *(.data)
        _edata = . ;                  /*symbol have a last address in the .data output section*/
    }>SRAM AT> FLASH    

    /* This is used by the startup in order to initialize the .bss section */
    .bss :
    {
        _sbss = . ;                  /*symbol have a first address in the .bss output section*/
        *(.bss)
        _ebss = . ;                  /*symbol have a last address in the .bss output section*/
    }>SRAM 

}