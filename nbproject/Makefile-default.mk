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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/menu/Menu.c src/sensors/bme.c src/sensors/bme280.c src/sensors/bmp.c src/sensors/bmp280.c src/sensors/buttons.c src/sensors/clock.c src/sensors/mhz19b.c src/interfaces/spi.c src/interfaces/twi.c src/interfaces/uart.c src/display/display.c src/display/font.c src/display/matrix.c src/debug.c src/utils/ring_buffer.c src/utils/timer.c src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/menu/Menu.o ${OBJECTDIR}/src/sensors/bme.o ${OBJECTDIR}/src/sensors/bme280.o ${OBJECTDIR}/src/sensors/bmp.o ${OBJECTDIR}/src/sensors/bmp280.o ${OBJECTDIR}/src/sensors/buttons.o ${OBJECTDIR}/src/sensors/clock.o ${OBJECTDIR}/src/sensors/mhz19b.o ${OBJECTDIR}/src/interfaces/spi.o ${OBJECTDIR}/src/interfaces/twi.o ${OBJECTDIR}/src/interfaces/uart.o ${OBJECTDIR}/src/display/display.o ${OBJECTDIR}/src/display/font.o ${OBJECTDIR}/src/display/matrix.o ${OBJECTDIR}/src/debug.o ${OBJECTDIR}/src/utils/ring_buffer.o ${OBJECTDIR}/src/utils/timer.o ${OBJECTDIR}/src/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/menu/Menu.o.d ${OBJECTDIR}/src/sensors/bme.o.d ${OBJECTDIR}/src/sensors/bme280.o.d ${OBJECTDIR}/src/sensors/bmp.o.d ${OBJECTDIR}/src/sensors/bmp280.o.d ${OBJECTDIR}/src/sensors/buttons.o.d ${OBJECTDIR}/src/sensors/clock.o.d ${OBJECTDIR}/src/sensors/mhz19b.o.d ${OBJECTDIR}/src/interfaces/spi.o.d ${OBJECTDIR}/src/interfaces/twi.o.d ${OBJECTDIR}/src/interfaces/uart.o.d ${OBJECTDIR}/src/display/display.o.d ${OBJECTDIR}/src/display/font.o.d ${OBJECTDIR}/src/display/matrix.o.d ${OBJECTDIR}/src/debug.o.d ${OBJECTDIR}/src/utils/ring_buffer.o.d ${OBJECTDIR}/src/utils/timer.o.d ${OBJECTDIR}/src/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/menu/Menu.o ${OBJECTDIR}/src/sensors/bme.o ${OBJECTDIR}/src/sensors/bme280.o ${OBJECTDIR}/src/sensors/bmp.o ${OBJECTDIR}/src/sensors/bmp280.o ${OBJECTDIR}/src/sensors/buttons.o ${OBJECTDIR}/src/sensors/clock.o ${OBJECTDIR}/src/sensors/mhz19b.o ${OBJECTDIR}/src/interfaces/spi.o ${OBJECTDIR}/src/interfaces/twi.o ${OBJECTDIR}/src/interfaces/uart.o ${OBJECTDIR}/src/display/display.o ${OBJECTDIR}/src/display/font.o ${OBJECTDIR}/src/display/matrix.o ${OBJECTDIR}/src/debug.o ${OBJECTDIR}/src/utils/ring_buffer.o ${OBJECTDIR}/src/utils/timer.o ${OBJECTDIR}/src/main.o

# Source Files
SOURCEFILES=src/menu/Menu.c src/sensors/bme.c src/sensors/bme280.c src/sensors/bmp.c src/sensors/bmp280.c src/sensors/buttons.c src/sensors/clock.c src/sensors/mhz19b.c src/interfaces/spi.c src/interfaces/twi.c src/interfaces/uart.c src/display/display.c src/display/font.c src/display/matrix.c src/debug.c src/utils/ring_buffer.c src/utils/timer.c src/main.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I ${DFP_DIR}/include
PACK_COMMON_OPTIONS=-B ${DFP_DIR}/gcc/dev/atmega328p



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/src/menu/Menu.o: src/menu/Menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/menu" 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o.d 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/menu/Menu.o.d" -MT "${OBJECTDIR}/src/menu/Menu.o.d" -MT ${OBJECTDIR}/src/menu/Menu.o  -o ${OBJECTDIR}/src/menu/Menu.o src/menu/Menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme.o: src/sensors/bme.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme.o.d" -MT "${OBJECTDIR}/src/sensors/bme.o.d" -MT ${OBJECTDIR}/src/sensors/bme.o  -o ${OBJECTDIR}/src/sensors/bme.o src/sensors/bme.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme280.o: src/sensors/bme280.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme280.o.d" -MT "${OBJECTDIR}/src/sensors/bme280.o.d" -MT ${OBJECTDIR}/src/sensors/bme280.o  -o ${OBJECTDIR}/src/sensors/bme280.o src/sensors/bme280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp.o: src/sensors/bmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp.o.d" -MT "${OBJECTDIR}/src/sensors/bmp.o.d" -MT ${OBJECTDIR}/src/sensors/bmp.o  -o ${OBJECTDIR}/src/sensors/bmp.o src/sensors/bmp.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp280.o: src/sensors/bmp280.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT ${OBJECTDIR}/src/sensors/bmp280.o  -o ${OBJECTDIR}/src/sensors/bmp280.o src/sensors/bmp280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/buttons.o: src/sensors/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/buttons.o.d" -MT "${OBJECTDIR}/src/sensors/buttons.o.d" -MT ${OBJECTDIR}/src/sensors/buttons.o  -o ${OBJECTDIR}/src/sensors/buttons.o src/sensors/buttons.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/clock.o: src/sensors/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/clock.o.d" -MT "${OBJECTDIR}/src/sensors/clock.o.d" -MT ${OBJECTDIR}/src/sensors/clock.o  -o ${OBJECTDIR}/src/sensors/clock.o src/sensors/clock.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/mhz19b.o: src/sensors/mhz19b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT ${OBJECTDIR}/src/sensors/mhz19b.o  -o ${OBJECTDIR}/src/sensors/mhz19b.o src/sensors/mhz19b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/spi.o: src/interfaces/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/spi.o.d" -MT "${OBJECTDIR}/src/interfaces/spi.o.d" -MT ${OBJECTDIR}/src/interfaces/spi.o  -o ${OBJECTDIR}/src/interfaces/spi.o src/interfaces/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/twi.o: src/interfaces/twi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/twi.o.d" -MT "${OBJECTDIR}/src/interfaces/twi.o.d" -MT ${OBJECTDIR}/src/interfaces/twi.o  -o ${OBJECTDIR}/src/interfaces/twi.o src/interfaces/twi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/uart.o: src/interfaces/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/uart.o.d" -MT "${OBJECTDIR}/src/interfaces/uart.o.d" -MT ${OBJECTDIR}/src/interfaces/uart.o  -o ${OBJECTDIR}/src/interfaces/uart.o src/interfaces/uart.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/display.o: src/display/display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/display.o.d 
	@${RM} ${OBJECTDIR}/src/display/display.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/display.o.d" -MT "${OBJECTDIR}/src/display/display.o.d" -MT ${OBJECTDIR}/src/display/display.o  -o ${OBJECTDIR}/src/display/display.o src/display/display.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/font.o: src/display/font.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/font.o.d 
	@${RM} ${OBJECTDIR}/src/display/font.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/font.o.d" -MT "${OBJECTDIR}/src/display/font.o.d" -MT ${OBJECTDIR}/src/display/font.o  -o ${OBJECTDIR}/src/display/font.o src/display/font.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/matrix.o: src/display/matrix.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/matrix.o.d 
	@${RM} ${OBJECTDIR}/src/display/matrix.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/matrix.o.d" -MT "${OBJECTDIR}/src/display/matrix.o.d" -MT ${OBJECTDIR}/src/display/matrix.o  -o ${OBJECTDIR}/src/display/matrix.o src/display/matrix.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/debug.o: src/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/debug.o.d 
	@${RM} ${OBJECTDIR}/src/debug.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/debug.o.d" -MT "${OBJECTDIR}/src/debug.o.d" -MT ${OBJECTDIR}/src/debug.o  -o ${OBJECTDIR}/src/debug.o src/debug.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/ring_buffer.o: src/utils/ring_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT ${OBJECTDIR}/src/utils/ring_buffer.o  -o ${OBJECTDIR}/src/utils/ring_buffer.o src/utils/ring_buffer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/timer.o: src/utils/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/timer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/timer.o.d" -MT "${OBJECTDIR}/src/utils/timer.o.d" -MT ${OBJECTDIR}/src/utils/timer.o  -o ${OBJECTDIR}/src/utils/timer.o src/utils/timer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/main.o.d" -MT "${OBJECTDIR}/src/main.o.d" -MT ${OBJECTDIR}/src/main.o  -o ${OBJECTDIR}/src/main.o src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/menu/Menu.o: src/menu/Menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/menu" 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o.d 
	@${RM} ${OBJECTDIR}/src/menu/Menu.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/menu/Menu.o.d" -MT "${OBJECTDIR}/src/menu/Menu.o.d" -MT ${OBJECTDIR}/src/menu/Menu.o  -o ${OBJECTDIR}/src/menu/Menu.o src/menu/Menu.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme.o: src/sensors/bme.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme.o.d" -MT "${OBJECTDIR}/src/sensors/bme.o.d" -MT ${OBJECTDIR}/src/sensors/bme.o  -o ${OBJECTDIR}/src/sensors/bme.o src/sensors/bme.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bme280.o: src/sensors/bme280.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bme280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bme280.o.d" -MT "${OBJECTDIR}/src/sensors/bme280.o.d" -MT ${OBJECTDIR}/src/sensors/bme280.o  -o ${OBJECTDIR}/src/sensors/bme280.o src/sensors/bme280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp.o: src/sensors/bmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp.o.d" -MT "${OBJECTDIR}/src/sensors/bmp.o.d" -MT ${OBJECTDIR}/src/sensors/bmp.o  -o ${OBJECTDIR}/src/sensors/bmp.o src/sensors/bmp.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/bmp280.o: src/sensors/bmp280.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/bmp280.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT "${OBJECTDIR}/src/sensors/bmp280.o.d" -MT ${OBJECTDIR}/src/sensors/bmp280.o  -o ${OBJECTDIR}/src/sensors/bmp280.o src/sensors/bmp280.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/buttons.o: src/sensors/buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/buttons.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/buttons.o.d" -MT "${OBJECTDIR}/src/sensors/buttons.o.d" -MT ${OBJECTDIR}/src/sensors/buttons.o  -o ${OBJECTDIR}/src/sensors/buttons.o src/sensors/buttons.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/clock.o: src/sensors/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/clock.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/clock.o.d" -MT "${OBJECTDIR}/src/sensors/clock.o.d" -MT ${OBJECTDIR}/src/sensors/clock.o  -o ${OBJECTDIR}/src/sensors/clock.o src/sensors/clock.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/sensors/mhz19b.o: src/sensors/mhz19b.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/sensors" 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o.d 
	@${RM} ${OBJECTDIR}/src/sensors/mhz19b.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT "${OBJECTDIR}/src/sensors/mhz19b.o.d" -MT ${OBJECTDIR}/src/sensors/mhz19b.o  -o ${OBJECTDIR}/src/sensors/mhz19b.o src/sensors/mhz19b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/spi.o: src/interfaces/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/spi.o.d" -MT "${OBJECTDIR}/src/interfaces/spi.o.d" -MT ${OBJECTDIR}/src/interfaces/spi.o  -o ${OBJECTDIR}/src/interfaces/spi.o src/interfaces/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/twi.o: src/interfaces/twi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/twi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/twi.o.d" -MT "${OBJECTDIR}/src/interfaces/twi.o.d" -MT ${OBJECTDIR}/src/interfaces/twi.o  -o ${OBJECTDIR}/src/interfaces/twi.o src/interfaces/twi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/interfaces/uart.o: src/interfaces/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/interfaces" 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o.d 
	@${RM} ${OBJECTDIR}/src/interfaces/uart.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/interfaces/uart.o.d" -MT "${OBJECTDIR}/src/interfaces/uart.o.d" -MT ${OBJECTDIR}/src/interfaces/uart.o  -o ${OBJECTDIR}/src/interfaces/uart.o src/interfaces/uart.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/display.o: src/display/display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/display.o.d 
	@${RM} ${OBJECTDIR}/src/display/display.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/display.o.d" -MT "${OBJECTDIR}/src/display/display.o.d" -MT ${OBJECTDIR}/src/display/display.o  -o ${OBJECTDIR}/src/display/display.o src/display/display.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/font.o: src/display/font.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/font.o.d 
	@${RM} ${OBJECTDIR}/src/display/font.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/font.o.d" -MT "${OBJECTDIR}/src/display/font.o.d" -MT ${OBJECTDIR}/src/display/font.o  -o ${OBJECTDIR}/src/display/font.o src/display/font.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/display/matrix.o: src/display/matrix.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/matrix.o.d 
	@${RM} ${OBJECTDIR}/src/display/matrix.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/display/matrix.o.d" -MT "${OBJECTDIR}/src/display/matrix.o.d" -MT ${OBJECTDIR}/src/display/matrix.o  -o ${OBJECTDIR}/src/display/matrix.o src/display/matrix.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/debug.o: src/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/debug.o.d 
	@${RM} ${OBJECTDIR}/src/debug.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/debug.o.d" -MT "${OBJECTDIR}/src/debug.o.d" -MT ${OBJECTDIR}/src/debug.o  -o ${OBJECTDIR}/src/debug.o src/debug.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/ring_buffer.o: src/utils/ring_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/ring_buffer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT "${OBJECTDIR}/src/utils/ring_buffer.o.d" -MT ${OBJECTDIR}/src/utils/ring_buffer.o  -o ${OBJECTDIR}/src/utils/ring_buffer.o src/utils/ring_buffer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/utils/timer.o: src/utils/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/utils" 
	@${RM} ${OBJECTDIR}/src/utils/timer.o.d 
	@${RM} ${OBJECTDIR}/src/utils/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/utils/timer.o.d" -MT "${OBJECTDIR}/src/utils/timer.o.d" -MT ${OBJECTDIR}/src/utils/timer.o  -o ${OBJECTDIR}/src/utils/timer.o src/utils/timer.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega328p ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DF_CPU=16000000UL -DDEBUG -DATMEGA328  -I "include" -I "include/display" -I "include/interfaces" -I "include/menu" -I "include/sensors" -I "include/utils" -Wall -MD -MP -MF "${OBJECTDIR}/src/main.o.d" -MT "${OBJECTDIR}/src/main.o.d" -MT ${OBJECTDIR}/src/main.o  -o ${OBJECTDIR}/src/main.o src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega328p ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/ledMatrix.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
