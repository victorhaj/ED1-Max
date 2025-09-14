; Nada faz
segment .data
;dados inicializados
segment .text
global _start
_start: ; ponto de entrada (ld)
sair:
    mov eax, 1 ; serviço EXIT
    int 80h ; syscall
; salvar como nadafaz.asm
;...$nasm -f elf64 nadafaz.asm
;...$ld nadafaz.o -o nadafaz
;...$./nadafaz