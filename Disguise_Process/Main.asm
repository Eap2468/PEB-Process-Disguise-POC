.code

GetParamInfo proc
	mov rax, gs:[60h]		;PEB struct
	mov rax, [rax + 20h]	;_RTL_USER_PROCESS_PARAMETERS struct (ProcessParameters)
	ret
GetParamInfo endp
end
