# PEB-Process-Disguise-POC
Disguises the current process from any application that utilizes the PEB structure for information.

In the PEB there is a [_RTL_USER_PROCESS_PARAMETERS](https://learn.microsoft.com/en-us/windows/win32/api/winternl/ns-winternl-rtl_user_process_parameters) structure that contains two [UNICODE_STRING](https://learn.microsoft.com/en-us/windows/win32/api/subauth/ns-subauth-unicode_string) structures, both of which have a buffer field which contains the path to the current executable and an array in the Reserved2 member that at the 6th position contains the directory of the process so simply by grabbing the RTL_USER_PROCESS_PARAMETERS structure and changing those parameters you can change the appearence of the file from any application that utilizes the PEB for information (like Process Explorer from sysinternals). However it doesn't work on Task Manager or ps (in cmd/powershell) because those utilize lower level apis which remove the need for the PEB

Credit to [Red Team Notes](https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/exploring-process-environment-block) for the Idea and [Crow](https://www.youtube.com/@crr0ww) for learning how to grab process information with masm assembly

![image](https://github.com/Eap2468/PEB-Process-Disguise-POC/assets/68890963/27724534-18b3-456c-a80e-9ab9a9ed0f79)
![image](https://github.com/Eap2468/PEB-Process-Disguise-POC/assets/68890963/0da07a47-cf51-4116-bcbc-d0a875d42248)
![image](https://github.com/Eap2468/PEB-Process-Disguise-POC/assets/68890963/968d2e36-ac3e-4d22-8c71-6c81f6478ea7)
