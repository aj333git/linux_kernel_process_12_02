cmd_/home/oem/kernel_process_12_02/modules.order := {   echo /home/oem/kernel_process_12_02/zones_kernel.ko; :; } | awk '!x[$$0]++' - > /home/oem/kernel_process_12_02/modules.order
