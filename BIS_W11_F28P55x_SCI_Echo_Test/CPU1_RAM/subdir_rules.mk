################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2101/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="C:/Users/user/workspace_ccstheia/BIS_W11_F28P55x_SCI_Echo_Test" --include_path="C:/ti/C2000Ware_26_01_00_00/device_support/f28p55x/common/include/" --include_path="C:/ti/C2000Ware_26_01_00_00/device_support/f28p55x/headers/include/" --include_path="C:/ti/ccs2101/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --cla_background_task=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2101/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu1 --vcu_support=vcrc -Ooff --include_path="C:/Users/user/workspace_ccstheia/BIS_W11_F28P55x_SCI_Echo_Test" --include_path="C:/ti/C2000Ware_26_01_00_00/device_support/f28p55x/common/include/" --include_path="C:/ti/C2000Ware_26_01_00_00/device_support/f28p55x/headers/include/" --include_path="C:/ti/ccs2101/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --cla_background_task=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


