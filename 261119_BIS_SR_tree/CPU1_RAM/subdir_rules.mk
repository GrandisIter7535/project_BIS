################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"D:/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="D:/BIS_Project/261119_BIS_SR" --include_path="C:/TI/C2000Ware_26_01_00_00" --include_path="D:/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=RAM --define=generic_ram_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/BIS_Project/261119_BIS_SR/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1455555062: ../led_ex1_blinky.syscfg
	@echo 'SysConfig - building file: "$<"'
	"D:/ccs/utils/sysconfig_1.28.1/sysconfig_cli.bat" -s "C:/TI/C2000Ware_26_01_00_00/.metadata/sdk.json" -d "F28P55x" -p "80PNA" -r "F28P55x_80PNA" --script "D:/BIS_Project/261119_BIS_SR/led_ex1_blinky.syscfg" --context "system" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1455555062 ../led_ex1_blinky.syscfg
syscfg/board.h: build-1455555062
syscfg/board.cmd.genlibs: build-1455555062
syscfg/board.opt: build-1455555062
syscfg/board.json: build-1455555062
syscfg/pinmux.csv: build-1455555062
syscfg/device.c: build-1455555062
syscfg/device.h: build-1455555062
syscfg/device_cmd.cmd: build-1455555062
syscfg/device_cmd.c: build-1455555062
syscfg/device_cmd.h: build-1455555062
syscfg/device_cmd.opt: build-1455555062
syscfg/device_cmd.cmd.genlibs: build-1455555062
syscfg/c2000ware_libraries.cmd.genlibs: build-1455555062
syscfg/c2000ware_libraries.opt: build-1455555062
syscfg/c2000ware_libraries.c: build-1455555062
syscfg/c2000ware_libraries.h: build-1455555062
syscfg/clocktree.h: build-1455555062
syscfg: build-1455555062

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"D:/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="D:/BIS_Project/261119_BIS_SR" --include_path="C:/TI/C2000Ware_26_01_00_00" --include_path="D:/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=RAM --define=generic_ram_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="D:/BIS_Project/261119_BIS_SR/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f28p55x_codestartbranch.obj: C:/TI/C2000Ware_26_01_00_00/device_support/f28p55x/common/source/f28p55x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"D:/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="D:/BIS_Project/261119_BIS_SR" --include_path="C:/TI/C2000Ware_26_01_00_00" --include_path="D:/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=RAM --define=generic_ram_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/BIS_Project/261119_BIS_SR/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


