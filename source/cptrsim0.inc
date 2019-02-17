{}{}{}

Procedure Evaluate; Assembler;
Asm
pusha
    Mov BX,offset ZXMem
    Mov DX,BX
    Add BX,Reg.PC
    Mov CX,BX
    Inc CX
    Inc Reg.PC
    Mov AL,[BX]
    Mov AH,0
    Rol AX,1
    Add AX,Offset @Tab
{POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR}
    Mov BX,AX
    {mov bx,cx}
    pushf
    pop ax
    mov al,reg.f
    push ax
    popf
    MOV AX,cs:[bx]
@Cll:call AX{ptr @tab}
popa
ret
{POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR POZOR}

@Tab:
{0}
dw offset @nop, offset @ldbcnn, offset @ldzbca, offset @incbc
dw offset @incb, offset @decb, offset @ldbn, offset @rlca

{8}
dw offset @nic, offset @addhlbc, offset @ldazbc, offset @decbc
dw offset @incc, offset @decc, offset @ldcn, offset @rrca

{16}
dw offset @nic, offset @lddenn, offset @ldzdea, offset @incde
dw offset @incd, offset @decd, offset @lddn, offset @rla

{24}
dw offset @nic, offset @addhlde, offset @ldazde, offset @decde
dw offset @ince, offset @dece, offset @lden, offset @rra

{32}
dw offset @nic, offset @ldhlnn, offset @ldznnhl, offset @inchl
dw offset @inch, offset @dech, offset @ldhn, offset @daa

{40}
dw offset @nic, offset @addhlhl, offset @ldhlznn, offset @dechl
dw offset @incl, offset @decl, offset @ldln, offset @cpl

{48}
dw offset @nic, offset @ldStPnn, offset @ldznna, offset @incStP
dw offset @inczhl, offset @deczhl, offset @ldzhln, offset @scf

dw offset @nic, offset @addhlsp, offset @ldaznn, offset @decstp
dw offset @inca, offset @deca, offset @ldan, offset @ccf

dw offset @ldbb, offset @ldbc, offset @ldbd, offset @ldbe
dw offset @ldbh, offset @ldbl, offset @ldbzhl, offset @ldba

dw offset @ldcb, offset @ldcc, offset @ldcd, offset @ldce
dw offset @ldch, offset @ldcl, offset @ldczhl, offset @ldca

dw offset @lddb, offset @lddc, offset @lddd, offset @ldde
dw offset @lddh, offset @lddl, offset @lddzhl, offset @ldda

dw offset @ldeb, offset @ldec, offset @lded, offset @ldee
dw offset @ldeh, offset @ldel, offset @ldezhl, offset @ldea

dw offset @ldhb, offset @ldhc, offset @ldhd, offset @ldhe
dw offset @ldhh, offset @ldhl, offset @ldhzhl, offset @ldha

dw offset @ldlb, offset @ldlc, offset @ldld, offset @ldle
dw offset @ldlh, offset @ldll, offset @ldlzhl, offset @ldla

dw offset @ldzhlb, offset @ldzhlc, offset @ldzhld, offset @ldzhle
dw offset @ldzhlh, offset @ldzhll, offset @halt, offset @ldzhla

dw offset @ldab, offset @ldac, offset @ldad, offset @ldae
dw offset @ldah, offset @ldal, offset @ldazhl, offset @ldaa

dw offset @addab, offset @addac, offset @addad, offset @addae
dw offset @addah, offset @addal, offset @addazhl, offset @addaa

dw offset @adcab, offset @adcac, offset @adcad, offset @adcae
dw offset @adcah, offset @adcal, offset @adcazhl, offset @adcaa

dw offset @subb, offset @subc, offset @subd, offset @sube
dw offset @subh, offset @subl, offset @subzhl, offset @suba

dw offset @sbcab, offset @sbcac, offset @sbcad, offset @sbcae
dw offset @sbcah, offset @sbcal, offset @sbcazhl, offset @sbcaa

dw offset @andb, offset @andc, offset @andd, offset @ande
dw offset @andh, offset @andl, offset @andzhl, offset @anda

dw offset @xorb, offset @xorc, offset @xord, offset @xore
dw offset @xorh, offset @xorl, offset @xorzhl, offset @xora

dw offset @orb, offset @orc, offset @ord, offset @ore
dw offset @orh, offset @orl, offset @orzhl, offset @ora

dw offset @cp_b, offset @cp_c, offset @cp_d, offset @cp_e
dw offset @cp_h, offset @cp_l, offset @cp_zhl, offset @cp_a

dw offset @retnz, offset @popbc, offset @jpnznn, offset @jpnn
dw offset @callnznn, offset @pushbc, offset @addan, offset @rst0

dw offset @retz, offset @ret, offset @jpznn, offset @nic
dw offset @callznn, offset @callnn, offset @adcan, offset @rst8

dw offset @retnc, offset @popde, offset @jpncnn, offset @outzna
dw offset @callncnn, offset @pushde, offset @subn, offset @rst10

dw offset @retc, offset @nic, offset @jpcnn, offset @inazn
dw offset @callcnn, offset @nic, offset @sbcan, offset @rst18

@nop:                   Ret

@nic:                   mov al,255
                        mov error,al
                        ret

@flags:
{W                 mov bl,0
                        jnp @np
                        mov bl,4
                   @np: mov bh,ah
                        jnz @nz
                        or bl,64
                   @nz:
                        jno @na
                        or bl,16
                   @na: and bh,168
                        or bh,bl
                        mov reg.f,bh}
                        pushf
                        pop ax
                        mov reg.f,al
                        ret
@carry:
{W                        mov al,reg.f
                        jnc @nee
                        or al,1
                        mov reg.f,al
                        ret
                  @nee: and al,254
                        mov reg.f,al}
                        pushf
                        pop ax
                        mov reg.f,al
                        ret

@ldbcnn:                Inc Reg.PC
                        Inc Reg.PC
                        Mov AX,[BX]
                        Mov Reg.BC,AX
                        Ret

@ldzbca:                Mov AX,Reg.BC
                        cmp ax,rommax
                        jl @ne0
                        cmp ax,mmax
                        jg @ne0
                        Add AX,DX
                        Mov BX,AX
                        Mov AL,Reg.A
                        Mov [BX],AL
                  @ne0: Ret

@incbc:                 inc reg.bc
                        Ret

@incb:                  mov ah,reg.b
                        inc ah
                        mov reg.b,ah
                        jmp @flags

@decb:                  mov ah,reg.b
                        dec ah
                        mov reg.b,ah
                        jmp @flags

@ldbn:                  inc reg.pc
                        mov al,[bx]
                        mov reg.b,al
                        ret

@rlca:                  mov al,reg.a
                        rol al,1
                        mov reg.a,al
                        jmp @carry

{9}
@addhlbc:               mov ax,reg.hl
                        add ax,reg.bc
                        mov reg.hl,ax
                        jmp @carry

@ldazbc:                Mov AX,Reg.BC
                        cmp ax,mmax
                        jg @po0
                        Add AX,DX
                        Mov BX,AX
                        Mov AL,[BX]
                        Mov Reg.A,AL
                        Ret
                   @po0:Mov al,255
                        mov reg.a,al
                        ret

@decbc:                 Mov AX,Reg.BC
                        Dec AX
                        Mov reg.BC,AX
                    {W    pushf
                        call @carry
                        popf}
                        jmp @flags

@incc:                  mov ah,reg.c
                        inc ah
                        mov reg.c,ah
                        jmp @flags

@decc:                  mov ah,reg.c
                        dec ah
                        mov reg.c,ah
                        jmp @flags

@ldcn:                  inc reg.pc
                        mov al,[bx]
                        mov reg.c,al
                        ret

@rrca:                  mov al,reg.a
                        ror al,1
                        mov reg.a,al
                        jmp @carry

@lddenn:                Inc Reg.PC
                        Inc Reg.PC
                        Mov AX,[BX]
                        Mov Reg.de,AX
                        Ret

@ldzdea:                Mov AX,Reg.de
                        cmp ax,rommax
                        jl @ne1
                        cmp ax,mmax
                        jg @ne1
                        Add AX,DX
                        Mov BX,AX
                        Mov AL,Reg.A
                        Mov [BX],AL
                  @ne1: Ret

@incde:                 inc reg.de
                        Ret

@incd:                  mov ah,reg.d
                        inc ah
                        mov reg.d,ah
                        jmp @flags

@decd:                  mov ah,reg.d
                        dec ah
                        mov reg.d,ah
                        jmp @flags

@lddn:                  inc reg.pc
                        mov al,[bx]
                        mov reg.d,al
                        ret

@rla:                   mov al,reg.a
                        rcl al,1
                        mov reg.a,al
                        jmp @carry

{wwwwwwwwwwwwwwwwwwww}

@addhlde:               mov ax,reg.hl
                        add ax,reg.de
                        mov reg.hl,ax
                        jmp @carry

@ldazde:                Mov AX,Reg.de
                        cmp ax,mmax
                        jg @po1
                        Add AX,DX
                        Mov BX,AX
                        Mov AL,[BX]
                        Mov Reg.A,AL
                        Ret
                   @po1:Mov al,255
                        mov reg.a,al
                        ret

@decde:                 Mov AX,Reg.de
                        Dec AX
                        Mov reg.de,AX
                        pushf
                        call @carry
                        popf
                        jmp @flags

@ince:                  mov ah,reg.e
                        inc ah
                        mov reg.e,ah
                        jmp @flags

@dece:                  mov ah,reg.e
                        dec ah
                        mov reg.e,ah
                        jmp @flags

@lden:                  inc reg.pc
                        mov al,[bx]
                        mov reg.e,al
                        ret

@rra:                   mov al,reg.a
                        rcr al,1
                        mov reg.a,al
                        jmp @carry
{33}
@ldhlnn:                Inc Reg.PC
                        Inc Reg.PC
                        Mov AX,[BX]
                        Mov Reg.hl,AX
                        Ret

@ldznnhl:              Inc Reg.PC
                        Inc Reg.PC
                        Mov AX,[BX]
                        mov bx,ax
                        Mov AX,Reg.hl
                        cmp bx,rommax
                        jl @ne2
                        cmp bx,mmax
                        je @ne3
                        jg @ne2
                        Add BX,DX
                        Mov [BX],AX
                  @ne2: Ret
                  @ne3: Add BX,DX
                        Mov [BX],AH
                        ret

@inchl:                 inc reg.hl
                        Ret

@inch:                  mov ah,reg.h
                        inc ah
                        mov reg.h,ah
                        jmp @flags

@dech:                  mov ah,reg.h
                        dec ah
                        mov reg.h,ah
                        jmp @flags

@ldhn:                  inc reg.pc
                        mov al,[bx]
                        mov reg.h,al
                        ret

@daa:                   jmp @nic

{2222222222222222222222222}
{41}
@addhlhl:               mov ax,reg.hl
                        add ax,ax
                        mov reg.hl,ax
                        jmp @carry

@ldhlznn:               inc reg.pc
                        inc reg.pc
                        mov ax,[bx]
                        cmp ax,mmax
                        jg @po11
                        je @po22
                        Add AX,DX
                        Mov BX,AX
                        Mov AX,[BX]
                        Mov Reg.hl,AX
                        Ret
                   @po11:Mov ax,65535
                        mov reg.hl,ax
                        ret
                   @po22:Add AX,DX
                        Mov BX,AX
                        Mov AL,[BX]
                        Mov ah,255
                        mov reg.hl,ax
                        ret

@dechl:                 Mov AX,Reg.hl
                        Dec AX
                        Mov reg.hl,AX
                        pushf
                        call @carry
                        popf
                        jmp @flags

@incl:                  mov ah,reg.l
                        inc ah
                        mov reg.l,ah
                        jmp @flags

@decl:                  mov ah,reg.l
                        dec ah
                        mov reg.l,ah
                        jmp @flags

@ldln:                  inc reg.pc
                        mov al,[bx]
                        mov reg.l,al
                        ret

@cpl:                   mov al,reg.a
                        xor al,255
                        mov reg.a,al
                        ret
{48}
@ldStPnn:                Inc Reg.PC
                        Inc Reg.PC
                        Mov AX,[BX]
                        Mov reg.StP,Ax
                        Ret

@ldznna:                Inc Reg.PC
                        Inc Reg.PC
                        Mov AX,[BX]
                        mov bx,ax
                        Mov AH,Reg.a
                        cmp bx,rommax
                        jl @ne22
                        cmp bx,mmax
                        jg @ne22
                        Add BX,DX
                        Mov [BX],Ah
                  @ne22:Ret

@incStP:                 inc reg.StP
                        Ret

@inczhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nq0
                        cmp bx,rommax
                        jle @nq1
                        add bx,dx
                        mov ah,[bx]
                        inc ah
                        mov [bx],ah
                        jmp @flags
                   @nq0:mov ah,255
                        jmp @flags
                   @nq1:mov ah,255
                        jmp @flags       {odtad}

@deczhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nw0
                        cmp bx,rommax
                        jle @nw1
                        add bx,dx
                        mov ah,[bx]
                        dec ah
                        mov [bx],ah
                        jmp @flags
                   @nw0:mov ah,255
                        jmp @flags
                   @nw1:mov ah,255
                        jmp @flags       {odtad}


@ldzhln:                inc reg.pc
                        mov al,[bx]
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                   @rt: ret


@scf:                   mov al,reg.f
                        or al,1
                        mov reg.f,al
                        ret

@addhlsp:               mov ax,reg.hl
                        add ax,reg.stp
                        mov reg.hl,ax
                        jmp @carry

@ldaznn:                inc reg.pc
                        inc reg.pc
                        mov ax,[bx]
                        cmp ax,mmax
                        jg @po21

                        Add AX,DX
                        Mov BX,AX
                        Mov Ah,[BX]
                        Mov Reg.a,Ah
                        Ret
                   @po21:Mov ah,255
                        mov reg.a,ah
                        ret

@decStP:                dec reg.StP
                        Ret

@inca:                  mov ah,reg.a
                        inc ah
                        mov reg.a,ah
                        jmp @flags

@deca:                  mov ah,reg.a
                        dec ah
                        mov reg.a,ah
                        jmp @flags

@ldan:                  inc reg.pc
                        mov al,[bx]
                        mov reg.a,al
                        ret

@ccf:                   mov ah,reg.f
                        xor ah,1
                        mov reg.f,ah
                        ret

{DO XX hotovo -> adr BX} {}{}{}
@ldbb:                  ret
@ldbc:                  mov ah,reg.c
                        mov reg.b,ah
                        ret
@ldbd:                  mov ah,reg.d
                        mov reg.b,ah
                        ret
@ldbe:                  mov ah,reg.e
                        mov reg.b,ah
                        ret
@ldbh:                  mov ah,reg.h
                        mov reg.b,ah
                        ret
@ldbl:                  mov ah,reg.l
                        mov reg.b,ah
                        ret

@ldbzhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nt0
                        add bx,dx
                        mov ah,[bx]
                        mov reg.b,ah
                        ret
                   @nt0:mov ah,255
                        mov reg.b,ah
                        ret

@ldba:                  mov ah,reg.a
                        mov reg.b,ah
                        ret

{}{}

@ldcb:                  mov ah,reg.b
                        mov reg.c,ah
                        ret
@ldcc:                  ret
@ldcd:                  mov ah,reg.d
                        mov reg.c,ah
                        ret
@ldce:                  mov ah,reg.e
                        mov reg.c,ah
                        ret
@ldch:                  mov ah,reg.h
                        mov reg.c,ah
                        ret
@ldcl:                  mov ah,reg.l
                        mov reg.c,ah
                        ret

@ldczhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nt3
                        add bx,dx
                        mov ah,[bx]
                        mov reg.c,ah
                        ret
                   @nt3:mov ah,255
                        mov reg.c,ah
                        ret

@ldca:                  mov ah,reg.a
                        mov reg.c,ah
                        ret

{}{}

@lddb:                  mov ah,reg.b
                        mov reg.d,ah
                        ret
@lddc:                  mov ah,reg.c
                        mov reg.d,ah
                        ret
@lddd:                  ret
@ldde:                  mov ah,reg.e
                        mov reg.d,ah
                        ret
@lddh:                  mov ah,reg.h
                        mov reg.d,ah
                        ret
@lddl:                  mov ah,reg.l
                        mov reg.d,ah
                        ret

@lddzhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nt4
                        add bx,dx
                        mov ah,[bx]
                        mov reg.d,ah
                        ret
                   @nt4:mov ah,255
                        mov reg.d,ah
                        ret

@ldda:                  mov ah,reg.a
                        mov reg.d,ah
                        ret

{}{}
{88}

@ldeb:                  mov ah,reg.b
                        mov reg.e,ah
                        ret
@ldec:                  mov ah,reg.c
                        mov reg.e,ah
                        ret
@lded:                  mov ah,reg.d
                        mov reg.e,ah
                        ret
@ldee:                  ret
@ldeh:                  mov ah,reg.h
                        mov reg.e,ah
                        ret
@ldel:                  mov ah,reg.l
                        mov reg.e,ah
                        ret

@ldezhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nt6
                        add bx,dx
                        mov ah,[bx]
                        mov reg.e,ah
                        ret
                   @nt6:mov ah,255
                        mov reg.e,ah
                        ret

@ldea:                  mov ah,reg.a
                        mov reg.e,ah
                        ret
{96}
@ldhb:                  mov ah,reg.b
                        mov reg.h,ah
                        ret
@ldhc:                  mov ah,reg.c
                        mov reg.h,ah
                        ret
@ldhd:                  mov ah,reg.d
                        mov reg.h,ah
                        ret
@ldhe:                  mov ah,reg.e
                        mov reg.h,ah
                        ret
@ldhh:                  ret
@ldhl:                  mov ah,reg.l
                        mov reg.h,ah
                        ret

@ldhzhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @nta
                        add bx,dx
                        mov ah,[bx]
                        mov reg.h,ah
                        ret
                   @nta:mov ah,255
                        mov reg.h,ah
                        ret

@ldha:                  mov ah,reg.a
                        mov reg.h,ah
                        ret

{104}
@ldlb:                  mov ah,reg.b
                        mov reg.l,ah
                        ret
@ldlc:                  mov ah,reg.c
                        mov reg.l,ah
                        ret
@ldld:                  mov ah,reg.d
                        mov reg.l,ah
                        ret
@ldle:                  mov ah,reg.e
                        mov reg.l,ah
                        ret
@ldlh:                  mov ah,reg.h
                        mov reg.l,ah
                        ret
@ldll:                  ret

@ldlzhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @ntb
                        add bx,dx
                        mov ah,[bx]
                        mov reg.l,ah
                        ret
                   @ntb:mov ah,255
                        mov reg.l,ah
                        ret

@ldla:                  mov ah,reg.a
                        mov reg.l,ah
                        ret

@ldzhlb:                mov al,reg.b
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt0
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                   @rt0: ret

@ldzhlc:                mov al,reg.c
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt1
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                  @rt1: ret

@ldzhld:                mov al,reg.d
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt2
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                  @rt2: ret

@ldzhle:                mov al,reg.e
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt3
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                  @rt3: ret

@ldzhlh:                mov al,reg.h
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt4
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                  @rt4: ret

@ldzhll:                mov al,reg.l
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt5
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                  @rt5: ret

@halt:                  mov ah,1
                        mov error,ah
                        ret

@ldzhla:                mov al,reg.a
                        mov bx,reg.hl
                        cmp bx,mmax
                        jg @rt6
                        cmp bx,rommax
                        jle @rt
                        add bx,dx
                        mov [bx],al
                  @rt6: ret

{**************************************}

@ldab:                  mov ah,reg.b
                        mov reg.a,ah
                        ret
@ldac:                  mov ah,reg.c
                        mov reg.a,ah
                        ret
@ldad:                  mov ah,reg.d
                        mov reg.a,ah
                        ret
@ldae:                  mov ah,reg.e
                        mov reg.a,ah
                        ret
@ldah:                  mov ah,reg.h
                        mov reg.a,ah
                        ret
@ldal:                  mov ah,reg.l
                        mov reg.a,ah
                        ret
@ldazhl:                mov bx,reg.hl
                        cmp bx,mmax
                        jg @ntc
                        add bx,dx
                        mov ah,[bx]
                        mov reg.a,ah
                        ret
                   @ntc:mov ah,255
                        mov reg.a,ah
                        ret

@ldaa:                  ret

@addab:                 mov ah,reg.b
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@addac:                 mov ah,reg.c
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@addad:                 mov ah,reg.d
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@addae:                 mov ah,reg.e
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@addah:                 mov ah,reg.h
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@addal:                 mov ah,reg.l
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@addazhl:               mov bx,reg.hl
                        cmp bx,mmax
                        jg @nte
                        add bx,dx
                        mov ah,[bx]
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

                   @nte:mov ah,255
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@addaa:                 mov ah,reg.a
                        add ah,ah
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@adcab:                 mov ah,reg.b
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@adcac:                 mov ah,reg.c
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@adcad:                 mov ah,reg.d
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@adcae:                 mov ah,reg.e
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@adcah:                 mov ah,reg.h
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@adcal:                 mov ah,reg.l
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@adcazhl:               mov bx,reg.hl
                        cmp bx,mmax
                        jg @ntf
                        add bx,dx
                        mov ah,[bx]
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

                   @ntf:mov ah,255
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@adcaa:                 mov ah,reg.a
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags
    {}{}{}{}{}
  {}{}{}{}{}{}{}{}{}{}
 {}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
 {}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
 {}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
  {}{}{}{}{}{}{}{}{}{}
    {}{}{}{}{}

@subb:                 mov al,reg.b
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@subc:                 mov al,reg.c
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@subd:                 mov al,reg.d
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sube:                 mov al,reg.e
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@subh:                 mov al,reg.h
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@subl:                 mov al,reg.l
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@subzhl:               mov bx,reg.hl
                        cmp bx,mmax
                        jg @ntg
                        add bx,dx
                        mov ah,[bx]
                        mov al,reg.a
                        sub al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

                   @ntg:mov ah,255
                        mov al,reg.a
                        sub al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@suba:                 mov ah,reg.a
                        sub ah,ah
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@sbcab:                 mov ah,reg.b       {KONIEC}
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sbcac:                 mov ah,reg.c
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sbcad:                 mov ah,reg.d
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sbcae:                 mov ah,reg.e
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sbcah:                 mov ah,reg.h
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sbcal:                 mov ah,reg.l
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@sbcazhl:               mov bx,reg.hl
                        cmp bx,mmax
                        jg @ntz

                        add bx,dx
                        mov ah,[bx]   {AH=(HL)}

                        {}
                        mov al,reg.a
                        mov bl,reg.f
                        and bl,1
                        sub al,bl
                        sbb al,al
                        mov ah,al
                        {}

                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

                   @ntz:mov ah,255

                        {}
                        mov al,reg.a
                        mov bl,reg.f
                        and bl,1
                        sub al,bl
                        sbb al,al
                        mov ah,al
                        {}

                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@sbcaa:                 mov ah,reg.a
                        mov al,reg.f
                        and al,1
                        sub al,reg.a
                        mov al,reg.a
                        sbb ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


{[                                         ]}
{[ þþþþ  þþ   þþ þþþþ   þþþþþ  þþþþþ       ]}
{[ þ     þ þ   þ þ   þ   þ     þ    þ      ]}
{[ þþþ   þ  þ  þ þ    þ  þþ    þ    þ      ]}
{[ þ     þ   þ þ þ   þ   þ     þ    þ      ]}
{[ þþþþ  þþ   þþ þþþþ   þþþþþ  þþþþþ  159  ]}
{[                                         ]}

@Andb:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        and ah,reg.b
                        mov reg.a,ah
                        jmp @flags

@Andc:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        and ah,reg.c
                        mov reg.a,ah
                        jmp @flags

@Andd:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        and ah,reg.d
                        mov reg.a,ah
                        jmp @flags

@Ande:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        and ah,reg.e
                        mov reg.a,ah
                        jmp @flags

@Andh:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        and ah,reg.h
                        mov reg.a,ah
                        jmp @flags

@Andl:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        and ah,reg.l
                        mov reg.a,ah
                        jmp @flags

@andzhl:                mov bx,reg.hl
                        mov al,reg.f
                        and al,254
                        cmp bx,mmax
                        jg @ntac
                        add bx,dx
                        mov ah,[bx]
                        mov al,reg.a
                        and ah,al
                        mov reg.a,ah
                        jmp @flags
                  @ntac:mov ah,255
                        mov al,reg.a
                        and ah,al
                        mov reg.a,ah
                        jmp @flags

@Anda:                  mov al,reg.f
                        and al,254
                        mov reg.f,al
                        mov ah,reg.a
                        and ah,ah
                        jmp @flags

@xorb:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        xor ah,reg.b
                        mov reg.a,ah
                        jmp @flags

@xorc:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        xor ah,reg.c
                        mov reg.a,ah
                        jmp @flags

@xord:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        xor ah,reg.d
                        mov reg.a,ah
                        jmp @flags

@xore:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        xor ah,reg.e
                        mov reg.a,ah
                        jmp @flags

@xorh:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        xor ah,reg.h
                        mov reg.a,ah
                        jmp @flags

@xorl:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        xor ah,reg.l
                        mov reg.a,ah
                        jmp @flags

@xorzhl:                mov bx,reg.hl
                        mov al,reg.f
                        and al,254
                        cmp bx,mmax
                        jg @wtc
                        add bx,dx
                        mov ah,[bx]
                        mov al,reg.a
                        xor ah,al
                        mov reg.a,ah
                        jmp @flags
                   @wtc:mov ah,255
                        mov al,reg.a
                        xor ah,al
                        mov reg.a,ah
                        jmp @flags

@xora:                  mov al,reg.f
                        and al,254
                        mov reg.f,al
                        mov ah,reg.a
                        xor ah,ah
                        jmp @flags


@orb:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        or ah,reg.b
                        mov reg.a,ah
                        jmp @flags

@orc:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        or ah,reg.c
                        mov reg.a,ah
                        jmp @flags

@ord:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        or ah,reg.d
                        mov reg.a,ah
                        jmp @flags

@ore:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        or ah,reg.e
                        mov reg.a,ah
                        jmp @flags

@orh:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        or ah,reg.h
                        mov reg.a,ah
                        jmp @flags

@orl:                  mov ah,reg.a
                        mov al,reg.f
                        and al,254
                        mov reg.f,al
                        or ah,reg.l
                        mov reg.a,ah
                        jmp @flags

@orzhl:                 mov bx,reg.hl
                        mov al,reg.f
                        and al,254
                        cmp bx,mmax
                        jg @watec
                        add bx,dx
                        mov ah,[bx]
                        mov al,reg.a
                        or ah,al
                        mov reg.a,ah
                        jmp @flags
                 @watec:mov ah,255
                        mov al,reg.a
                        or ah,al
                        mov reg.a,ah
                        jmp @flags

@ora:                  mov al,reg.f
                        and al,254
                        mov reg.f,al
                        mov ah,reg.a
                        or ah,ah
                        jmp @flags

@cp_b:                 mov al,reg.b
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

@cp_c:                 mov al,reg.c
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

@cp_d:                 mov al,reg.d
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

@cp_e:                 mov al,reg.e
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

@cp_h:                 mov al,reg.h
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags


@cp_l:                 mov al,reg.l
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

@cp_zhl:               mov bx,reg.hl
                        cmp bx,mmax
                        jng @netgw
                        mov ah,255
                        jmp @faaf
                @netgw: add bx,dx
                        mov ah,[bx]
                 @faaf: mov al,reg.a
                        sub al,ah
                        mov ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

@cp_a:                 mov al,reg.a
                        mov ah,reg.a
                        sub ah,al
                        pushf
                        call @carry
                        popf
                        jmp @flags

{SERIEN 2}
@retnz:                 mov al,reg.f
                        and al,64
                        jz @w0w
                        mov ax,reg.stp
                        add ax, dx
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.pc,ax
                        inc reg.stp
                        inc reg.stp
                   @w0w:ret

@popbc:                 mov ax,reg.stp
                        add ax, word ptr zxmem
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.bc,ax
                        inc reg.stp
                        inc reg.stp
                        ret

@jpnznn:                mov al,reg.f{ide}
                        inc reg.pc
                        inc reg.pc
                        and al,64
                        jnz @w1w
                        mov ax,[bx]
                        mov reg.pc,ax
                   @w1w:ret

@jpnn:                  mov ax,[bx]
                        mov reg.pc,ax
                        ret

@callnznn:              mov al,reg.f
                        inc reg.pc
                        inc reg.pc
                        and al,64
                        jnz @w0w
                        dec reg.stp
                        dec reg.stp
                        mov ax,reg.stp  {AX->SP}
                        add ax, dx
                        mov cx,ax       {CX->SP}
                        mov dx,reg.pc   {DX=PC}
                        mov ax,[bx]
                        mov reg.pc,ax
                        mov bx,cx
                        mov [bx],dx
                        ret

@pushbc:                dec reg.stp
                        dec reg.stp
                        Mov bx,reg.stp
                        add bx,dx
                        mov dx,reg.bc
                        mov [bx],dx
                        ret

@addan:                 inc reg.pc
                        mov ah,[bx]
                        mov al,reg.a
                        add ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@rst0:                  dec reg.stp
                        dec reg.stp
                        Mov bx,reg.stp
                        add bx,dx
                        mov dx,reg.pc
                        mov [bx],dx
                        mov ax,0
                        mov reg.pc,ax
                        ret
{SERIEN 3}
@retz:                  mov al,reg.f
                        and al,64
                        jnz @w0w
                        mov ax,reg.stp
                        add ax, dx
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.pc,ax
                        inc reg.stp
                        inc reg.stp
                        ret

@ret:                   mov ax,reg.stp
                        add ax, dx
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.pc,ax
                        inc reg.stp
                        inc reg.stp
                        ret

@jpznn:                 mov al,reg.f{ide}
                        inc reg.pc
                        inc reg.pc
                        and al,64
                        jz @w1w
                        mov ax,[bx]
                        mov reg.pc,ax
                        ret


@callznn:               mov al,reg.f
                        inc reg.pc
                        inc reg.pc
                        and al,64
                        jz @w0w
                        dec reg.stp
                        dec reg.stp
                        mov ax,reg.stp  {AX->SP}
                        add ax, dx
                        mov cx,ax       {CX->SP}
                        mov dx,reg.pc   {DX=PC}
                        mov ax,[bx]
                        mov bx,cx
                        mov [bx],dx
                        ret

@callnn:                dec reg.stp
                        dec reg.stp
                        mov ax,reg.stp  {AX->SP}
                        add ax, dx
                        mov cx,ax       {CX->SP}
                        mov dx,reg.pc   {DX=PC}
                        Inc DX
                        Inc DX
                        mov ax,[bx]
                        mov reg.pc,ax
                        mov bx,cx
                        mov [bx],dx
                        ret


@adcan:                 inc reg.pc
                        mov ah,[bx]
                        mov al,reg.f
                        and al,1
                        add al,reg.a
                        adc ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags


@rst8:                  dec reg.stp
                        dec reg.stp
                        Mov bx,reg.stp
                        add bx,dx
                        mov dx,reg.pc
                        mov [bx],dx
                        mov ax,8
                        mov reg.pc,ax
                        ret

{SERIEN 4}
@retnc:                 mov al,reg.f
                        and al,1
                        jz @w0w
                        mov ax,reg.stp
                        add ax, dx
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.pc,ax
                        inc reg.stp
                        inc reg.stp
                        ret

@popde:                 mov ax,reg.stp
                        add ax, dx
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.de,ax
                        inc reg.stp
                        inc reg.stp
                        ret

@jpncnn:                mov al,reg.f
                        inc reg.pc
                        inc reg.pc
                        and al,1
                        jnz @w1w
                        mov ax,[bx]
                        mov reg.pc,ax
                        ret


@outzna:                mov al,[bx]
                        inc reg.pc
                        mov ah,0
                        mov bx, offset ports
                        add bl,al
                        adc bh,0
                        add bl,al
                        adc bh,0
                        mov al,reg.a
                        mov [bx],al
                        ret


@callncnn:              mov al,reg.f
                        inc reg.pc
                        inc reg.pc
                        and al,1
                        jnz @w0w
                        dec reg.stp
                        dec reg.stp
                        mov ax,reg.stp  {AX->SP}
                        add ax, dx
                        mov cx,ax       {CX->SP}
                        mov dx,reg.pc   {DX=PC}
                        mov ax,[bx]
                        mov reg.pc,ax
                        mov bx,cx
                        mov [bx],dx
                        ret

@pushde:                dec reg.stp
                        dec reg.stp
                        Mov bx,reg.stp
                        add bx,dx
                        mov dx,reg.de
                        mov [bx],dx
                        ret

@subn:                  inc reg.pc
                        mov al,[bx]
                        mov ah,reg.a
                        sub ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@rst10:                 dec reg.stp
                        dec reg.stp
                        Mov bx,reg.stp
                        add bx,dx
                        mov dx,reg.pc
                        mov [bx],dx
                        mov ax,16
                        mov reg.pc,ax
                        ret

   {} {} {} {} {} {} {} {}
 {} {                   } {}
 {    NEXT: 216=RET C      }
 {} {                   } {}
   {} {} {} {} {} {} {} {}

@retc:                  mov al,reg.f
                        and al,1
                        jnz @w0w
                        mov ax,reg.stp
                        add ax, dx
                        mov bx,ax
                        mov ax,[bx]
                        mov reg.pc,ax
                        inc reg.stp
                        inc reg.stp
                        ret

@jpcnn:                 mov al,reg.f
                        inc reg.pc
                        inc reg.pc
                        and al,1
                        jz @w1w
                        mov ax,[bx]
                        mov reg.pc,ax
                        ret


@inazn:                 mov al,[bx]
                        inc reg.pc
                        mov ah,0
                        mov bx, offset ports
                        add bl,al
                        adc bh,0
                        add bl,al
                        adc bh,0
                        mov al,[bx]
                        mov reg.a,al
                        ret


@callcnn:               mov al,reg.f
                        inc reg.pc
                        inc reg.pc
                        and al,1
                        jz @w0w
                        dec reg.stp
                        dec reg.stp
                        mov ax,reg.stp  {AX->SP}
                        add ax, dx
                        mov cx,ax       {CX->SP}
                        mov dx,reg.pc   {DX=PC}
                        mov ax,[bx]
                        mov reg.pc,ax
                        mov bx,cx
                        mov [bx],dx
                        ret

@sbcan:                 inc reg.pc
                        mov ah,[bx]
                        mov al,reg.f
                        and al,1
                        sub ah,al
                        mov al,reg.a
                        sbb al,ah
                        mov ah,al
                        mov reg.a,ah
                        pushf
                        call @carry
                        popf
                        jmp @flags

@rst18:                 dec reg.stp
                        dec reg.stp
                        Mov bx,reg.stp
                        add bx,dx
                        mov dx,reg.pc
                        mov [bx],dx
                        mov ax,24
                        mov reg.pc,ax
                        ret

end;