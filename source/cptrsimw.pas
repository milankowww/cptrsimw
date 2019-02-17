{$A+,B-,D+,E+,F-,G+,I-,L+,N+,O+,P+,Q-,R-,S+,T-,V-,X+}
{$M 16384,0,655360}
{$D CompSim (C) WWW 1994}
Program ComputerSimulator;
Uses Dos, Crt;
Const DiStPlay:string[20]='! ÿÿp@@Fÿÿ';
      Flgs:string[32]='SignZero****AuxC****Prty****Crry';
      Hexa:string[16]='0123456789ABCDEF';
      MMax=20479;
      RomMax=16384;
      prmax=17+5;
      prhogram:array[0..prmax] of byte=
      (
       6, 127,      {ld b,0}
       62, 0,     {ld a,0}
       211, 0,
       211,1,
       211,2,
       211,3,    {out (0),a}
       60,        {inc a}
       204, 19, 0,{call z,19}
       195, 4, 0, {jmp 4}
 {13}  120,       {ld a,b}
       211, 1,    {out (1),a}
              {xor a}
       201        {ret}

      );
(*      prmax=26+5+8+2;
      prhogram:array[0..prmax] of byte=
      (
      62, 25,                      {LD A,25}
      1, 4, 4,                     {LD BC,1028}
      145,                         {SUB C}
      15,15,15,15,15,15,15,15,15,  {9*RRCA}
      33, 1, 0,                    {LD HL,1}
      9,                           {ADD HL,BC}
      34, 2, 16,                   {LD (4098),HL}
      33, 2, 16,                   {LD HL,4098}
      126,                         {LD A,(HL)}
      168,                         {XOR B} {ZERO=0}
      198,17,                      {ADD A,17}
      214,5,                       {SUB 5}
      214,5,
      214,5,
      214,6,
      197,                         {PUSH BC}
      201,                         {RET}
      196, 0, 0                    {CALL NZ,0}
      ); *)
Type SincRegs=record
           case integer of
            0: (BC, DE, HL, AF, WZ, StP, PC       :Word);
            1: (C,B,E,D,L,H,F,A,W,Z     ,StPl,StPh,pcl,pch   :Byte);
           end;
         {     1        }
         {   þþþþþþþ    }
         { 32þ     þ 2  }
         {   þ 64  þ    }
         {   þþþþþþþ    }
         {   þ     þ    }
         { 16þ     þ 4  }
         {   þþþþþþþ    }
         {     8    þ128}

Var



{Byte}

{Char}

{Integer}
         Cyk: Integer;
{LongInt}

{String}

{Real}

{Registers}

{Procedure}

{Pointer}

{ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *}
{* * * * * * *}ZXMem:Array[0..MMAX+6] of byte;{* * * * * * * }
{ *  EXTRA  * } Reg: SincRegs; Error:Byte;    { *  EXTRA  * *}
{* * * * * * *} Ports: Array[0..255] of word; {* * * * * * * }
{ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *}
Function DHex(x:word):string;
var zv:string[4];
    x1:word;
Begin
    x1:=x;
    zv:=hexa[1+(x1 div 4096)];
    x1:=x1 mod 4096;
    zv:=zv+hexa[1+(x1 div 256)];
    x1:=x1 mod 256;
    zv:=zv+hexa[1+(x1 div 16)];
    x1:=x1 mod 16;
    zv:=zv+hexa[1+x1];
    dhex:=zv;
End;
Function Hex(x:byte):string;
Begin
    hex:=hexa[1+(x div 16)]+hexa[1+(x mod 16)];
End;
Function Bin(x:word):string;
var zv:word;
    z2:string[8];
begin
      zv:=x;
      z2:='';
      repeat
        z2:=hexa[1+(zv mod 2)]+z2;
        zv:=zv div 2;
      until zv=0;
      bin:=copy('0000000'+z2,length(z2),8);
end;
Function DBin(x:word):string;
var zv:word;
    z2:string[16];
begin
      zv:=x;
      z2:='';
      repeat
        z2:=hexa[1+(zv mod 2)]+z2;
        zv:=zv div 2;
      until zv=0;
      dbin:=copy('000000000000000'+z2,length(z2),8);
end;

{ASS/DISASS}
{$I CPTRSIM1.INC}
{ASS/DISASS}

Procedure PrintRegs;
Var
    P,Q,R,S,T,U,V: Integer;
Begin

     GotoXY(1,21);
     For P:=0 to 4 do
     For S:=0 to 3 do
     begin
     TextBackground (1);
     write (' ');
     For Q:=0 to 3 do
     Begin
      R:=ord(DiStPlay[P*4+Q+1]);
      If R<255 then If (R and (Ports[S] and 255))>0 then
      write ('±') else write ('ú') else write (' ');
     End;
     if s<3 then
     if p<4 then
      write ('  ')
      else                       if (ports[s] and 128)=128 then write ('þ ')
                                    else write ('  ')
       else
     begin
     write (' ');
      TextBackground (3);
      Write (' ');
      case p of
        0: Write ('BC:',reg.BC:5,'³B:',reg.B:3,'³C:',reg.C:3,'³DE:',reg.DE:5,'³D:',reg.D:3,'³E:',reg.E:3,'           ');
        1: begin
        Write('HL:',reg.HL:5,'³H:',reg.H:3,'³L:',reg.L:3,'³SP:',reg.StP:5,'³A:',reg.A:3,'=#',hex(reg.A),'=',bin(reg.a));
        if reg.a>=128 then write ((reg.a-256):4) else write (' ',reg.a:3);
           end;
        2: begin
            Write ('PC:',reg.pc:5,'³F: ');
            u:=128;
            for t:=0 to 7 do
            begin

             if (reg.F and u)>0 then textcolor(15) else textcolor(8);
             write (copy(flgs,1+4*t,4),' ');

             u:=u div 2;
            end;
            textcolor(15);
           end;
        3: begin
        write ('StackList:');
           for u:=0 to 6 do
           if reg.StP+2*u+1<mmax then write((zxmem[reg.StP+2*u]+256*zxmem[reg.StP+2*u+1]):6) else write ('      ');

           end;

        4: begin
Write('Next: ',Disass1b(ZXMem[reg.pc], ZXMem[reg.pc+1], ZXMem[reg.pc+2],u));
Write('/',Disass1b(ZXMem[reg.pc+u], ZXMem[reg.pc+1+u], ZXMem[reg.pc+2+u],v));
t:=0;
repeat
write ('/',ZXMem[reg.pc+u+v+t]);
inc(t);
until wherex>76;
if wherex<79 then
for t:=wherex to 79 do write (' ');

           end;
      end {case};
     end;

     end;
End;
{EVALUATE}

{$I CPTRSIM0.INC}

{EVALUATE}


{}{}{}


Begin
    TextColor      (15);
    TextBackground ( 0);
    ClrScr;
    MemW[$b800:3838]:=$57;
    zxmem[0]:=1;
    zxmem[1]:=1;
    zxmem[2]:=0;

    for cyk:=0 to prmax do zxmem[cyk]:=prhogram[cyk];
    Reg.BC:=0;
    Reg.DE:=0;
    Reg.HL:=0;
    Reg.AF:=64;
    Reg.StP:=mmax;
    Reg.PC:=0;
    Reg.WZ:=0;
    PrintRegs;
    Ports[0]:=0;
    Ports[1]:=0;
    Ports[2]:=0;
    Ports[3]:=0;
    TextBackground(6);
    For cyk:=1 to 20 do
    begin
        gotoxy(71,cyk);
        write ('          ');
    end;
    repeat
        Evaluate;
        PrintRegs;


    until readkey=#27;
End.
