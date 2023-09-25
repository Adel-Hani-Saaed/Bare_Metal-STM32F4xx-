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
    }>FLASH                           /*>FLASH AT> FLASH (Vitual and load addresses are the same location in FLASH Memory)*/

    .data :
    {
        *(.data)
    }>SRAM AT> FLASH    

}