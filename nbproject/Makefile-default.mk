#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/menu/Menu.c src/sensors/bme.c src/sensors/bme280.c src/sensors/bmp.c src/sensors/bmp280.c src/sensors/buttons.c src/sensors/clock.c src/sensors/mhz19b.c src/interfaces/spi.c src/interfaces/twi.c src/interfaces/uart.c src/display/display.c src/display/font.c src/display/matrix.c src/debug.c src/utils/ring_buffer.c src/utils/timer.c src/main.c src/menu/settings_menu.c src/memory/at24c32.c src/memory/settings.c src/utils/utils.c src/utils/adc.c src/utils/proc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/menu/Menu.o ${OBJECTDIR}/src/sensors/bme.o ${OBJECTDIR}/src/sensors/bme280.o ${OBJECTDIR}/src/sensors/bmp.o ${OBJECTDIR}/src/sensors/bmp280.o ${OBJECTDIR}/src/sensors/buttons.o ${OBJECTDIR}/src/sensors/clock.o ${OBJECTDIR}/src/sensors/mhz19b.o ${OBJECTDIR}/src/interfaces/spi.o ${OBJECTDIR}/src/interfaces/twi.o ${OBJECTDIR}/src/interfaces/uart.o ${OBJECTDIR}/src/display/display.o ${OBJECTDIR}/src/display/font.o ${OBJECTDIR}/src/display/matrix.o ${OBJECTDIR}/src/debug.o ${OBJECTDIR}/src/utils/ring_buffer.o ${OBJECTDIR}/src/utils/timer.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/menu/settings_menu.o ${OBJECTDIR}/src/memory/at24c32.o ${OBJECTDIR}/src/memory/settings.o ${OBJECTDIR}/src/utils/utils.o ${OBJECTDIR}/src/utils/adc.o ${OBJECTDIR}/src/utils/proc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/menu/Menu.o.d ${OBJECTDIR}/src/sensors/bme.o.d ${OBJECTDIR}/src/sensors/bme280.o.d ${OBJECTDIR}/src/sensors/bmp.o.d ${OBJECTDIR}/src/sensors/bmp280.o.d ${OBJECTDIR}/src/sensors/buttons.o.d ${OBJECTDIR}/src/sensors/clock.o.d ${OBJECTDIR}/src/sensors/mhz19b.o.d ${OBJECTDIR}/src/interfaces/spi.o.d ${OBJECTDIR}/src/interfaces/twi.o.d ${OBJECTDIR}/src/interfaces/uart.o.d ${OBJECTDIR}/src/display/display.o.d ${OBJECTDIR}/src/display/font.o.d ${OBJECTDIR}/src/display/matrix.o.d ${OBJECTDIR}/src/debug.o.d ${OBJECTDIR}/src/utils/ring_buffer.o.d ${OBJECTDIR}/src/utils/timer.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/menu/settings_menu.o.d ${OBJECTDIR}/src/memory/at24c32.o.d ${OBJECTDIR}/src/memory/settings.o.d ${OBJECTDIR}/src/utils/utils.o.d ${OBJECTDIR}/src/utils/adc.o.d ${OBJECTDIR}/src/utils/proc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/menu/Menu.o ${OBJECTDIR}/src/sensors/bme.o ${OBJECTDIR}/src/sensors/bme280.o ${OBJECTDIR}/src/sensors/bmp.o ${OBJECTDIR}/src/sensors/bmp280.o ${OBJECTDIR}/src/sensors/buttons.o ${OBJECTDIR}/src/sensors/clock.o ${OBJECTDIR}/src/sensors/mhz19b.o ${OBJECTDIR}/src/interfaces/spi.o ${OBJECTDIR}/src/interfaces/twi.o ${OBJECTDIR}/src/interfaces/uart.o ${OBJECTDIR}/src/display/display.o ${OBJECTDIR}/src/display/font.o ${OBJECTDIR}/src/display/matrix.o ${OBJECTDIR}/src/debug.o ${OBJECTDIR}/src/utils/ring_buffer.o ${OBJECTDIR}/src/utils/timer.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/menu/settings_menu.o ${OBJECTDIR}/src/memory/at24c32.o ${OBJECTDIR}/src/memory/settings.o ${OBJECTDIR}/src/utils/utils.o ${OBJECTDIR}/src/utils/adc.o ${OBJECTDIR}/src/utils/proc.o

# Source Files
SOURCEFILES=src/menu/Menu.c src/sensors/bme.c src/sensors/bme280.c src/sensors/bmp.c src/sensors/bmp280.c src/sensors/buttons.c src/sensors/clock.c src/sensors/mhz19b.c src/interfaces/spi.c src/interfaces/twi.c src/interfaces/uart.c src/display/display.c src/display/font.c src/display/matrix.c src/debug.c src/utils/ring_buffer.c src/utils/timer.c src/main.c src/menu/settings_menu.c src/memory/at24c32.c src/memory/settings.c src/utils/utils.c src/utils/adc.c src/utils/proc.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega328p"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328P
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/menu/Menu.o: src/menu/Menu.c  .generated_files/flags/default/20706707861ac6cd714e61aeb7d150b42d1f4cd0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/menu" 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o.d 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/menu/Menu.o.d" -MT "${OBJECTDIR}/src/menu/Menu.o.d" -MT ${OBJECTDIR}/src/menu/Menu.o  -o ${OBJECTDIR}/src/menu/Menu.o src/menu/Menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme.o: src/sensors/bme.c  .generated_files/flags/default/24250d61e414f8b2fa629836445de640372a7d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme.o.d" -MT "${OBJECTDIR}/src/sensors/bme.o.d" -MT ${OBJECTDIR}/src/sensors/bme.o  -o ${OBJECTDIR}/src/sensors/bme.o src/sensors/bme.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme280.o: src/sensors/bme280.c  .generated_files/flags/default/7d35a803e7aba0ac62a530a9845d892f2b1d8fd5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme280.o.d" -MT "${OBJECTDIR}/src/sensors/bme280.o.d" -MT ${OBJECTDIR}/src/sensors/bme280.o  -o ${OBJECTDIR}/src/sensors/bme280.o src/sensors/bme280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp.o: src/sensors/bmp.c  .generated_files/flags/default/9db2ab1a0ba81f3ba2c9b2891dc6735c52cd6ba9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp.o.d" -MT "${OBJECTDIR}/src/sensors/bmp.o.d" -MT ${OBJECTDIR}/src/sensors/bmp.o  -o ${OBJECTDIR}/src/sensors/bmp.o src/sensors/bmp.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp280.o: src/sensors/bmp280.c  .generated_files/flags/default/2d239d2ff93d33976ce6201defc5996b2a87c390 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT ${OBJECTDIR}/src/sensors/bmp280.o  -o ${OBJECTDIR}/src/sensors/bmp280.o src/sensors/bmp280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/buttons.o: src/sensors/buttons.c  .generated_files/flags/default/4aa528a7123d27828ac68dab58a36e7a1f4c0caf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/buttons.o.d" -MT "${OBJECTDIR}/src/sensors/buttons.o.d" -MT ${OBJECTDIR}/src/sensors/buttons.o  -o ${OBJECTDIR}/src/sensors/buttons.o src/sensors/buttons.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/clock.o: src/sensors/clock.c  .generated_files/flags/default/c383866d9c9cb0778560f7b049bcd5c6574c41bf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/clock.o.d" -MT "${OBJECTDIR}/src/sensors/clock.o.d" -MT ${OBJECTDIR}/src/sensors/clock.o  -o ${OBJECTDIR}/src/sensors/clock.o src/sensors/clock.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/mhz19b.o: src/sensors/mhz19b.c  .generated_files/flags/default/9153ca291db4afd44f059b513e7e771ee99dce0d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT ${OBJECTDIR}/src/sensors/mhz19b.o  -o ${OBJECTDIR}/src/sensors/mhz19b.o src/sensors/mhz19b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/spi.o: src/interfaces/spi.c  .generated_files/flags/default/a7e3524dd2467f423f2bd3953894097d19f73d86 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/spi.o.d" -MT "${OBJECTDIR}/src/interfaces/spi.o.d" -MT ${OBJECTDIR}/src/interfaces/spi.o  -o ${OBJECTDIR}/src/interfaces/spi.o src/interfaces/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/twi.o: src/interfaces/twi.c  .generated_files/flags/default/6f19655c879c1884ab4a7d8517e6c890b1bdfa27 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/twi.o.d" -MT "${OBJECTDIR}/src/interfaces/twi.o.d" -MT ${OBJECTDIR}/src/interfaces/twi.o  -o ${OBJECTDIR}/src/interfaces/twi.o src/interfaces/twi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/uart.o: src/interfaces/uart.c  .generated_files/flags/default/cf1bdbddff67453c2716e5dfa2e923451541518e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/uart.o.d" -MT "${OBJECTDIR}/src/interfaces/uart.o.d" -MT ${OBJECTDIR}/src/interfaces/uart.o  -o ${OBJECTDIR}/src/interfaces/uart.o src/interfaces/uart.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/display.o: src/display/display.c  .generated_files/flags/default/e6976aa2cfbd377e6acb0e00ae2ffc0161ca1236 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/display.o.d 
	@${RM} ${OBJECTDIR}/src/display/display.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/display.o.d" -MT "${OBJECTDIR}/src/display/display.o.d" -MT ${OBJECTDIR}/src/display/display.o  -o ${OBJECTDIR}/src/display/display.o src/display/display.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/font.o: src/display/font.c  .generated_files/flags/default/3415c61b66859521f751d2b4f6511689bc57dab8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/font.o.d 
	@${RM} ${OBJECTDIR}/src/display/font.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/font.o.d" -MT "${OBJECTDIR}/src/display/font.o.d" -MT ${OBJECTDIR}/src/display/font.o  -o ${OBJECTDIR}/src/display/font.o src/display/font.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/matrix.o: src/display/matrix.c  .generated_files/flags/default/464b206fa38c23ba5284ac269cd1bceff948e4de .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/matrix.o.d 
	@${RM} ${OBJECTDIR}/src/display/matrix.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/matrix.o.d" -MT "${OBJECTDIR}/src/display/matrix.o.d" -MT ${OBJECTDIR}/src/display/matrix.o  -o ${OBJECTDIR}/src/display/matrix.o src/display/matrix.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/debug.o: src/debug.c  .generated_files/flags/default/e721e9535a4ac0be9cf30a4d49de6e5464b85040 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/debug.o.d 
	@${RM} ${OBJECTDIR}/src/debug.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/debug.o.d" -MT "${OBJECTDIR}/src/debug.o.d" -MT ${OBJECTDIR}/src/debug.o  -o ${OBJECTDIR}/src/debug.o src/debug.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/ring_buffer.o: src/utils/ring_buffer.c  .generated_files/flags/default/f51a8c403dc4b3bfa62194fa3ce9ae57e1aa43b1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT ${OBJECTDIR}/src/utils/ring_buffer.o  -o ${OBJECTDIR}/src/utils/ring_buffer.o src/utils/ring_buffer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/timer.o: src/utils/timer.c  .generated_files/flags/default/f43247171ac9bd5fcd48909557b7d69ed5bd3e4b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/timer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/timer.o.d" -MT "${OBJECTDIR}/src/utils/timer.o.d" -MT ${OBJECTDIR}/src/utils/timer.o  -o ${OBJECTDIR}/src/utils/timer.o src/utils/timer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/2b36aa4e5d198c426cd14bc4e20abdc76020a425 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/main.o.d" -MT "${OBJECTDIR}/src/main.o.d" -MT ${OBJECTDIR}/src/main.o  -o ${OBJECTDIR}/src/main.o src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/menu/settings_menu.o: src/menu/settings_menu.c  .generated_files/flags/default/a8534943aeeb76218ec21caec94a19627400ea39 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/menu" 
	@${RM} ${OBJECTDIR}/src/menu/settings_menu.o.d 
	@${RM} ${OBJECTDIR}/src/menu/settings_menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/menu/settings_menu.o.d" -MT "${OBJECTDIR}/src/menu/settings_menu.o.d" -MT ${OBJECTDIR}/src/menu/settings_menu.o  -o ${OBJECTDIR}/src/menu/settings_menu.o src/menu/settings_menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/memory/at24c32.o: src/memory/at24c32.c  .generated_files/flags/default/5ee38075ea9655aecc8cada74ad9ae50456a9d98 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/memory" 
	@${RM} ${OBJECTDIR}/src/memory/at24c32.o.d 
	@${RM} ${OBJECTDIR}/src/memory/at24c32.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/memory/at24c32.o.d" -MT "${OBJECTDIR}/src/memory/at24c32.o.d" -MT ${OBJECTDIR}/src/memory/at24c32.o  -o ${OBJECTDIR}/src/memory/at24c32.o src/memory/at24c32.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/memory/settings.o: src/memory/settings.c  .generated_files/flags/default/dca7d9e92e97b34546253ae734e24f014c0bd774 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/memory" 
	@${RM} ${OBJECTDIR}/src/memory/settings.o.d 
	@${RM} ${OBJECTDIR}/src/memory/settings.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/memory/settings.o.d" -MT "${OBJECTDIR}/src/memory/settings.o.d" -MT ${OBJECTDIR}/src/memory/settings.o  -o ${OBJECTDIR}/src/memory/settings.o src/memory/settings.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/utils.o: src/utils/utils.c  .generated_files/flags/default/66174cc040f96d692d9c1c3a955c47e041c6e224 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/utils.o.d 
	@${RM} ${OBJECTDIR}/src/utils/utils.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/utils.o.d" -MT "${OBJECTDIR}/src/utils/utils.o.d" -MT ${OBJECTDIR}/src/utils/utils.o  -o ${OBJECTDIR}/src/utils/utils.o src/utils/utils.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/adc.o: src/utils/adc.c  .generated_files/flags/default/ca7239e58ad066d39b0b1ed34f4beba66fd35282 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/adc.o.d 
	@${RM} ${OBJECTDIR}/src/utils/adc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/adc.o.d" -MT "${OBJECTDIR}/src/utils/adc.o.d" -MT ${OBJECTDIR}/src/utils/adc.o  -o ${OBJECTDIR}/src/utils/adc.o src/utils/adc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/proc.o: src/utils/proc.c  .generated_files/flags/default/6e851bcb1c304172e171fc17592b83a6345af507 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/proc.o.d 
	@${RM} ${OBJECTDIR}/src/utils/proc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/proc.o.d" -MT "${OBJECTDIR}/src/utils/proc.o.d" -MT ${OBJECTDIR}/src/utils/proc.o  -o ${OBJECTDIR}/src/utils/proc.o src/utils/proc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/menu/Menu.o: src/menu/Menu.c  .generated_files/flags/default/92d05011511e0e0862317666c5f4655d97ddc6a3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/menu" 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o.d 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/menu/Menu.o.d" -MT "${OBJECTDIR}/src/menu/Menu.o.d" -MT ${OBJECTDIR}/src/menu/Menu.o  -o ${OBJECTDIR}/src/menu/Menu.o src/menu/Menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme.o: src/sensors/bme.c  .generated_files/flags/default/f0d71fd2490a433ae9b782669ab3d318493c9d1d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme.o.d" -MT "${OBJECTDIR}/src/sensors/bme.o.d" -MT ${OBJECTDIR}/src/sensors/bme.o  -o ${OBJECTDIR}/src/sensors/bme.o src/sensors/bme.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme280.o: src/sensors/bme280.c  .generated_files/flags/default/fec0c883879aee9b7c88fee6464d0bc8c1321886 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme280.o.d" -MT "${OBJECTDIR}/src/sensors/bme280.o.d" -MT ${OBJECTDIR}/src/sensors/bme280.o  -o ${OBJECTDIR}/src/sensors/bme280.o src/sensors/bme280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp.o: src/sensors/bmp.c  .generated_files/flags/default/66d2e5940b8dc879350720aabc9b42368d5061bc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp.o.d" -MT "${OBJECTDIR}/src/sensors/bmp.o.d" -MT ${OBJECTDIR}/src/sensors/bmp.o  -o ${OBJECTDIR}/src/sensors/bmp.o src/sensors/bmp.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp280.o: src/sensors/bmp280.c  .generated_files/flags/default/a014c66baaafe129a10db259e4fdfa3a4748f1b8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT ${OBJECTDIR}/src/sensors/bmp280.o  -o ${OBJECTDIR}/src/sensors/bmp280.o src/sensors/bmp280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/buttons.o: src/sensors/buttons.c  .generated_files/flags/default/6366e6e25c211d5ba2a664f80d25da31e7db0775 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/buttons.o.d" -MT "${OBJECTDIR}/src/sensors/buttons.o.d" -MT ${OBJECTDIR}/src/sensors/buttons.o  -o ${OBJECTDIR}/src/sensors/buttons.o src/sensors/buttons.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/clock.o: src/sensors/clock.c  .generated_files/flags/default/d0a0dbe41871588a90001e745b0c9ffa76273ae7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/clock.o.d" -MT "${OBJECTDIR}/src/sensors/clock.o.d" -MT ${OBJECTDIR}/src/sensors/clock.o  -o ${OBJECTDIR}/src/sensors/clock.o src/sensors/clock.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/mhz19b.o: src/sensors/mhz19b.c  .generated_files/flags/default/b2d2f72ffc02c0621cc88073c9a09374d5fa18c7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT ${OBJECTDIR}/src/sensors/mhz19b.o  -o ${OBJECTDIR}/src/sensors/mhz19b.o src/sensors/mhz19b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/spi.o: src/interfaces/spi.c  .generated_files/flags/default/5d2156057ca50329182c3b1209c4528d445d7c5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/spi.o.d" -MT "${OBJECTDIR}/src/interfaces/spi.o.d" -MT ${OBJECTDIR}/src/interfaces/spi.o  -o ${OBJECTDIR}/src/interfaces/spi.o src/interfaces/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/twi.o: src/interfaces/twi.c  .generated_files/flags/default/40fbbe2fe5c2ef0ef315a852f9c028acc5fa4d5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/twi.o.d" -MT "${OBJECTDIR}/src/interfaces/twi.o.d" -MT ${OBJECTDIR}/src/interfaces/twi.o  -o ${OBJECTDIR}/src/interfaces/twi.o src/interfaces/twi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/uart.o: src/interfaces/uart.c  .generated_files/flags/default/a9658a52073307c68528c37b6e1e02f86779f57f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/uart.o.d" -MT "${OBJECTDIR}/src/interfaces/uart.o.d" -MT ${OBJECTDIR}/src/interfaces/uart.o  -o ${OBJECTDIR}/src/interfaces/uart.o src/interfaces/uart.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/display.o: src/display/display.c  .generated_files/flags/default/7175525a4108b0b7175e80d339ff75820c7ebb90 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/display.o.d 
	@${RM} ${OBJECTDIR}/src/display/display.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/display.o.d" -MT "${OBJECTDIR}/src/display/display.o.d" -MT ${OBJECTDIR}/src/display/display.o  -o ${OBJECTDIR}/src/display/display.o src/display/display.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/font.o: src/display/font.c  .generated_files/flags/default/700e65392e65a832f9b4e040d94395183989c364 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/font.o.d 
	@${RM} ${OBJECTDIR}/src/display/font.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/font.o.d" -MT "${OBJECTDIR}/src/display/font.o.d" -MT ${OBJECTDIR}/src/display/font.o  -o ${OBJECTDIR}/src/display/font.o src/display/font.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/matrix.o: src/display/matrix.c  .generated_files/flags/default/d4c558cbe7bbccfd6d23112226fddd131b403d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/matrix.o.d 
	@${RM} ${OBJECTDIR}/src/display/matrix.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/matrix.o.d" -MT "${OBJECTDIR}/src/display/matrix.o.d" -MT ${OBJECTDIR}/src/display/matrix.o  -o ${OBJECTDIR}/src/display/matrix.o src/display/matrix.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/debug.o: src/debug.c  .generated_files/flags/default/ceb302405291be25685ef4d4defdd14b047f00f0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/debug.o.d 
	@${RM} ${OBJECTDIR}/src/debug.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/debug.o.d" -MT "${OBJECTDIR}/src/debug.o.d" -MT ${OBJECTDIR}/src/debug.o  -o ${OBJECTDIR}/src/debug.o src/debug.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/ring_buffer.o: src/utils/ring_buffer.c  .generated_files/flags/default/2086f592a50d7ec8e816a7cad13e7097b9dbed4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT ${OBJECTDIR}/src/utils/ring_buffer.o  -o ${OBJECTDIR}/src/utils/ring_buffer.o src/utils/ring_buffer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/timer.o: src/utils/timer.c  .generated_files/flags/default/96e358952008d2ac7921718b5839f3ca5b37474b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/timer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/timer.o.d" -MT "${OBJECTDIR}/src/utils/timer.o.d" -MT ${OBJECTDIR}/src/utils/timer.o  -o ${OBJECTDIR}/src/utils/timer.o src/utils/timer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/a02d5304512c3d70c87a2065397d947e6d834649 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/main.o.d" -MT "${OBJECTDIR}/src/main.o.d" -MT ${OBJECTDIR}/src/main.o  -o ${OBJECTDIR}/src/main.o src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/menu/settings_menu.o: src/menu/settings_menu.c  .generated_files/flags/default/4e8f2ed751b8819f7ab1779ee9c66b7552cb2d9b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/menu" 
	@${RM} ${OBJECTDIR}/src/menu/settings_menu.o.d 
	@${RM} ${OBJECTDIR}/src/menu/settings_menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/menu/settings_menu.o.d" -MT "${OBJECTDIR}/src/menu/settings_menu.o.d" -MT ${OBJECTDIR}/src/menu/settings_menu.o  -o ${OBJECTDIR}/src/menu/settings_menu.o src/menu/settings_menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/memory/at24c32.o: src/memory/at24c32.c  .generated_files/flags/default/f4b4159c2e4cdc472f65ed484f6091152fcc50d0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/memory" 
	@${RM} ${OBJECTDIR}/src/memory/at24c32.o.d 
	@${RM} ${OBJECTDIR}/src/memory/at24c32.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/memory/at24c32.o.d" -MT "${OBJECTDIR}/src/memory/at24c32.o.d" -MT ${OBJECTDIR}/src/memory/at24c32.o  -o ${OBJECTDIR}/src/memory/at24c32.o src/memory/at24c32.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/memory/settings.o: src/memory/settings.c  .generated_files/flags/default/147c764ff7945a7545838cedc6633d674555b208 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/memory" 
	@${RM} ${OBJECTDIR}/src/memory/settings.o.d 
	@${RM} ${OBJECTDIR}/src/memory/settings.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/memory/settings.o.d" -MT "${OBJECTDIR}/src/memory/settings.o.d" -MT ${OBJECTDIR}/src/memory/settings.o  -o ${OBJECTDIR}/src/memory/settings.o src/memory/settings.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/utils.o: src/utils/utils.c  .generated_files/flags/default/6b4c34a173a4d8d7f4baa549c60646708cfffe2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/utils.o.d 
	@${RM} ${OBJECTDIR}/src/utils/utils.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/utils.o.d" -MT "${OBJECTDIR}/src/utils/utils.o.d" -MT ${OBJECTDIR}/src/utils/utils.o  -o ${OBJECTDIR}/src/utils/utils.o src/utils/utils.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/adc.o: src/utils/adc.c  .generated_files/flags/default/148d009569c9efe4806a28027c874ed56e1ba735 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/adc.o.d 
	@${RM} ${OBJECTDIR}/src/utils/adc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/adc.o.d" -MT "${OBJECTDIR}/src/utils/adc.o.d" -MT ${OBJECTDIR}/src/utils/adc.o  -o ${OBJECTDIR}/src/utils/adc.o src/utils/adc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/proc.o: src/utils/proc.c  .generated_files/flags/default/516383a8a52ba859ce4d3d80bdfe3f1ad9364280 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/proc.o.d 
	@${RM} ${OBJECTDIR}/src/utils/proc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DATMEGA328 -DCLOCK_IC=M41T81  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -I "include/memory" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/proc.o.d" -MT "${OBJECTDIR}/src/utils/proc.o.d" -MT ${OBJECTDIR}/src/utils/proc.o  -o ${OBJECTDIR}/src/utils/proc.o src/utils/proc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/ledMatrix.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
