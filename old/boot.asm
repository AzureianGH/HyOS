; Simple bootloader
[org 0x7C00] ; set the origin of the code to 0x7C00
mov si, text_string
call print_string
jmp $

text_string db 'Hydrix OS', 0x0a, 0x0d

put_char: ; subroutine to print string
    mov ah, 0x0E ; int 10h 'print char' function
    .repeat:
        lodsb ; grab a byte from SI
        cmp al, 0 ; check if it's the null terminator
        je .done ; if so, jump to done
        int 0x10 ; otherwise, print it
        jmp .repeat ; repeat the process
    .done:
        ret ; return from subroutine

times 510-($-$$) db 0 ; pad the rest of the boot sector with 0s
dw 0xAA55 ; standard PC boot signature