################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-45364991: ../c2000.syscfg
	@echo 'SysConfig - building file: "$<"'
	"C:/ti/ccs2100/ccs/utils/sysconfig_1.28.0/sysconfig_cli.bat" -s "C:/ti/c2000/C2000Ware_26_01_00_00/.metadata/sdk.json" -d "F28P55x" -p "128PDT" -r "F28P55x_128PDT" --script "C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test/c2000.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-45364991 ../c2000.syscfg
syscfg/board.h: build-45364991
syscfg/board.cmd.genlibs: build-45364991
syscfg/board.opt: build-45364991
syscfg/board.json: build-45364991
syscfg/pinmux.csv: build-45364991
syscfg/c2000ware_libraries.cmd.genlibs: build-45364991
syscfg/c2000ware_libraries.opt: build-45364991
syscfg/c2000ware_libraries.c: build-45364991
syscfg/c2000ware_libraries.h: build-45364991
syscfg/clocktree.h: build-45364991
syscfg: build-45364991

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test" --include_path="C:/ti/c2000/C2000Ware_26_01_00_00" --include_path="C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test/device" --include_path="C:/ti/c2000/C2000Ware_26_01_00_00/driverlib/f28p55x/driverlib/" --include_path="C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test" --include_path="C:/ti/c2000/C2000Ware_26_01_00_00" --include_path="C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test/device" --include_path="C:/ti/c2000/C2000Ware_26_01_00_00/driverlib/f28p55x/driverlib/" --include_path="C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/user/Documents/project_BIS/BIS_W11_F28P55x_Empty_Test/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


