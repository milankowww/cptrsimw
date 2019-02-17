
Const Tab:Array[0..255] of
                      record
                         N:String[4];          {Instruction name}
                         X:Byte;               {Assembler argument count}
                         P:Array[0..1] of Byte;{Asm argument type}
                        RX:Byte;               {Real number of arguments 0/1/2}
                      end=

(
{0-7}
(N:'NOP';X:0;P:(0,0);RX:0),
(N:'LD';X:2;P:(8,13);RX:2),
(N:'LD';X:2;P:(22,7);RX:0),
(N:'INC';X:1;P:(8,0);RX:0),
(N:'INC';X:1;P:(0,0);RX:0),
(N:'DEC';X:1;P:(0,0);RX:0),
(N:'LD';X:2;P:(0,14);RX:1),
(N:'RLCA';X:0;P:(0,0);RX:0),
{8-15}
(N:'err';X:0;P:(0,0);RX:0),
(N:'ADD';X:2;P:(10,8);RX:0),
(N:'LD';X:2;P:(7,22);RX:0),
(N:'DEC';X:1;P:(8,0);RX:0),
(N:'INC';X:1;P:(1,0);RX:0),
(N:'DEC';X:1;P:(1,0);RX:0),
(N:'LD';X:2;P:(1,14);RX:1),
(N:'RRCA';X:0;P:(0,0);RX:0),
{16-23}
(N:'err';X:0;P:(0,0);RX:0),
(N:'LD';X:2;P:(9,13);RX:2),
(N:'LD';X:2;P:(23,7);RX:0),
(N:'INC';X:1;P:(9,0);RX:0),
(N:'INC';X:1;P:(2,0);RX:0),
(N:'DEC';X:1;P:(2,0);RX:0),
(N:'LD';X:2;P:(2,14);RX:1),
(N:'RLA';X:0;P:(0,0);RX:0),
{24-31}
(N:'err';X:0;P:(0,0);RX:0),
(N:'ADD';X:2;P:(10,9);RX:0),
(N:'LD';X:2;P:(7,23);RX:0),
(N:'DEC';X:1;P:(9,0);RX:0),
(N:'INC';X:1;P:(3,0);RX:0),
(N:'DEC';X:1;P:(3,0);RX:0),
(N:'LD';X:2;P:(3,14);RX:1),
(N:'RRA';X:0;P:(0,0);RX:0),
{32-39}
(N:'err';X:0;P:(0,0);RX:0),
(N:'LD';X:2;P:(10,13);RX:2),
(N:'LD';X:2;P:(24,10);RX:2),
(N:'INC';X:1;P:(10,0);RX:0),
(N:'INC';X:1;P:(4,0);RX:0),
(N:'DEC';X:1;P:(4,0);RX:0),
(N:'LD';X:2;P:(4,14);RX:1),
(N:'DAA';X:0;P:(0,0);RX:0),
{40-47}
(N:'err';X:0;P:(0,0);RX:0),
(N:'ADD';X:2;P:(10,10);RX:0),
(N:'LD';X:2;P:(10,24);RX:2),
(N:'DEC';X:1;P:(10,0);RX:0),
(N:'INC';X:1;P:(5,0);RX:0),
(N:'DEC';X:1;P:(5,0);RX:0),
(N:'LD';X:2;P:(5,14);RX:1),
(N:'CPL';X:0;P:(0,0);RX:0),
{48-55}
(N:'err';X:0;P:(0,0);RX:0),
(N:'LD';X:2;P:(12,13);RX:2),
(N:'LD';X:2;P:(24,7);RX:2),
(N:'INC';X:1;P:(12,0);RX:0),
(N:'INC';X:1;P:(6,0);RX:0),
(N:'DEC';X:1;P:(6,0);RX:0),
(N:'LD';X:2;P:(6,14);RX:1),
(N:'SCF';X:0;P:(0,0);RX:0),
{56-63}
(N:'err';X:0;P:(0,0);RX:0),
(N:'ADD';X:2;P:(10,12);RX:0),
(N:'LD';X:2;P:(7,24);RX:2),
(N:'DEC';X:1;P:(12,0);RX:0),
(N:'INC';X:1;P:(7,0);RX:0),
(N:'DEC';X:1;P:(7,0);RX:0),
(N:'LD';X:2;P:(7,14);RX:1),
(N:'CCF';X:0;P:(0,0);RX:0),
{64-71}
(N:'LD';X:2;P:(0,0);RX:0),
(N:'LD';X:2;P:(0,1);RX:0),
(N:'LD';X:2;P:(0,2);RX:0),
(N:'LD';X:2;P:(0,3);RX:0),
(N:'LD';X:2;P:(0,4);RX:0),
(N:'LD';X:2;P:(0,5);RX:0),
(N:'LD';X:2;P:(0,6);RX:0),
(N:'LD';X:2;P:(0,7);RX:0),
{72-79}
(N:'LD';X:2;P:(1,0);RX:0),
(N:'LD';X:2;P:(1,1);RX:0),
(N:'LD';X:2;P:(1,2);RX:0),
(N:'LD';X:2;P:(1,3);RX:0),
(N:'LD';X:2;P:(1,4);RX:0),
(N:'LD';X:2;P:(1,5);RX:0),
(N:'LD';X:2;P:(1,6);RX:0),
(N:'LD';X:2;P:(1,7);RX:0),

{80-87}
(N:'LD';X:2;P:(2,0);RX:0),
(N:'LD';X:2;P:(2,1);RX:0),
(N:'LD';X:2;P:(2,2);RX:0),
(N:'LD';X:2;P:(2,3);RX:0),
(N:'LD';X:2;P:(2,4);RX:0),
(N:'LD';X:2;P:(2,5);RX:0),
(N:'LD';X:2;P:(2,6);RX:0),
(N:'LD';X:2;P:(2,7);RX:0),
{88-95}
(N:'LD';X:2;P:(3,0);RX:0),
(N:'LD';X:2;P:(3,1);RX:0),
(N:'LD';X:2;P:(3,2);RX:0),
(N:'LD';X:2;P:(3,3);RX:0),
(N:'LD';X:2;P:(3,4);RX:0),
(N:'LD';X:2;P:(3,5);RX:0),
(N:'LD';X:2;P:(3,6);RX:0),
(N:'LD';X:2;P:(3,7);RX:0),
{96-103}
(N:'LD';X:2;P:(4,0);RX:0),
(N:'LD';X:2;P:(4,1);RX:0),
(N:'LD';X:2;P:(4,2);RX:0),
(N:'LD';X:2;P:(4,3);RX:0),
(N:'LD';X:2;P:(4,4);RX:0),
(N:'LD';X:2;P:(4,5);RX:0),
(N:'LD';X:2;P:(4,6);RX:0),
(N:'LD';X:2;P:(4,7);RX:0),
{104-111}
(N:'LD';X:2;P:(5,0);RX:0),
(N:'LD';X:2;P:(5,1);RX:0),
(N:'LD';X:2;P:(5,2);RX:0),
(N:'LD';X:2;P:(5,3);RX:0),
(N:'LD';X:2;P:(5,4);RX:0),
(N:'LD';X:2;P:(5,5);RX:0),
(N:'LD';X:2;P:(5,6);RX:0),
(N:'LD';X:2;P:(5,7);RX:0),
{112-119}
(N:'LD';X:2;P:(6,0);RX:0),
(N:'LD';X:2;P:(6,1);RX:0),
(N:'LD';X:2;P:(6,2);RX:0),
(N:'LD';X:2;P:(6,3);RX:0),
(N:'LD';X:2;P:(6,4);RX:0),
(N:'LD';X:2;P:(6,5);RX:0),
(N:'HALT';X:0;P:(0,0);RX:0),
(N:'LD';X:2;P:(6,7);RX:0),
{120-127}
(N:'LD';X:2;P:(7,0);RX:0),
(N:'LD';X:2;P:(7,1);RX:0),
(N:'LD';X:2;P:(7,2);RX:0),
(N:'LD';X:2;P:(7,3);RX:0),
(N:'LD';X:2;P:(7,4);RX:0),
(N:'LD';X:2;P:(7,5);RX:0),
(N:'LD';X:2;P:(7,6);RX:0),
(N:'LD';X:2;P:(7,7);RX:0),
{128-135}
(N:'ADD';X:2;P:(0,0);RX:0),
(N:'ADD';X:2;P:(0,1);RX:0),
(N:'ADD';X:2;P:(0,2);RX:0),
(N:'ADD';X:2;P:(0,3);RX:0),
(N:'ADD';X:2;P:(0,4);RX:0),
(N:'ADD';X:2;P:(0,5);RX:0),
(N:'ADD';X:2;P:(0,6);RX:0),
(N:'ADD';X:2;P:(0,7);RX:0),
{136-143}
(N:'ADC';X:2;P:(0,0);RX:0),
(N:'ADC';X:2;P:(0,1);RX:0),
(N:'ADC';X:2;P:(0,2);RX:0),
(N:'ADC';X:2;P:(0,3);RX:0),
(N:'ADC';X:2;P:(0,4);RX:0),
(N:'ADC';X:2;P:(0,5);RX:0),
(N:'ADC';X:2;P:(0,6);RX:0),
(N:'ADC';X:2;P:(0,7);RX:0),
{144-151}
(N:'SUB';X:1;P:(0,0);RX:0),
(N:'SUB';X:1;P:(1,0);RX:0),
(N:'SUB';X:1;P:(2,0);RX:0),
(N:'SUB';X:1;P:(3,0);RX:0),
(N:'SUB';X:1;P:(4,0);RX:0),
(N:'SUB';X:1;P:(5,0);RX:0),
(N:'SUB';X:1;P:(6,0);RX:0),
(N:'SUB';X:1;P:(7,0);RX:0),
{152-159}
(N:'SBC';X:2;P:(0,0);RX:0),
(N:'SBC';X:2;P:(0,1);RX:0),
(N:'SBC';X:2;P:(0,2);RX:0),
(N:'SBC';X:2;P:(0,3);RX:0),
(N:'SBC';X:2;P:(0,4);RX:0),
(N:'SBC';X:2;P:(0,5);RX:0),
(N:'SBC';X:2;P:(0,6);RX:0),
(N:'SBC';X:2;P:(0,7);RX:0),
{160-167}
(N:'AND';X:1;P:(0,0);RX:0),
(N:'AND';X:1;P:(1,0);RX:0),
(N:'AND';X:1;P:(2,0);RX:0),
(N:'AND';X:1;P:(3,0);RX:0),
(N:'AND';X:1;P:(4,0);RX:0),
(N:'AND';X:1;P:(5,0);RX:0),
(N:'AND';X:1;P:(6,0);RX:0),
(N:'AND';X:1;P:(7,0);RX:0),
{168-175}
(N:'XOR';X:1;P:(0,0);RX:0),
(N:'XOR';X:1;P:(1,0);RX:0),
(N:'XOR';X:1;P:(2,0);RX:0),
(N:'XOR';X:1;P:(3,0);RX:0),
(N:'XOR';X:1;P:(4,0);RX:0),
(N:'XOR';X:1;P:(5,0);RX:0),
(N:'XOR';X:1;P:(6,0);RX:0),
(N:'XOR';X:1;P:(7,0);RX:0),
{176-183}
(N:'OR';X:1;P:(0,0);RX:0),
(N:'OR';X:1;P:(1,0);RX:0),
(N:'OR';X:1;P:(2,0);RX:0),
(N:'OR';X:1;P:(3,0);RX:0),
(N:'OR';X:1;P:(4,0);RX:0),
(N:'OR';X:1;P:(5,0);RX:0),
(N:'OR';X:1;P:(6,0);RX:0),
(N:'OR';X:1;P:(7,0);RX:0),
{184-191}
(N:'CP';X:1;P:(0,0);RX:0),
(N:'CP';X:1;P:(1,0);RX:0),
(N:'CP';X:1;P:(2,0);RX:0),
(N:'CP';X:1;P:(3,0);RX:0),
(N:'CP';X:1;P:(4,0);RX:0),
(N:'CP';X:1;P:(5,0);RX:0),
(N:'CP';X:1;P:(6,0);RX:0),
(N:'CP';X:1;P:(7,0);RX:0),
{192-199}
(N:'RET';X:1;P:(16,0);RX:0),
(N:'POP';X:1;P:(8,0);RX:0),
(N:'JP';X:2;P:(16,13);RX:2),
(N:'JP';X:1;P:(13,0);RX:2),
(N:'CALL';X:2;P:(16,13);RX:2),
(N:'PUSH';X:1;P:(8,0);RX:0),
(N:'ADD';X:2;P:(7,14);RX:1),
(N:'RST';X:1;P:(25,0);RX:0),
{200-207}
(N:'RET';X:1;P:(15,0);RX:0),
(N:'RET';X:0;P:(0,0);RX:0),
(N:'JP';X:2;P:(15,13);RX:2),
(N:'err';X:0;P:(0,0);RX:0),
(N:'CALL';X:2;P:(15,13);RX:2),
(N:'CALL';X:1;P:(13,0);RX:2),
(N:'ADC';X:2;P:(7,14);RX:1),
(N:'RST';X:1;P:(26,0);RX:0),
{208-215}
(N:'RET';X:1;P:(21,0);RX:0),
(N:'POP';X:1;P:(9,0);RX:0),
(N:'JP';X:2;P:(21,13);RX:2),
(N:'OUT';X:2;P:(14,7);RX:1),
(N:'CALL';X:2;P:(21,13);RX:2),
(N:'PUSH';X:1;P:(9,0);RX:0),
(N:'SUB';X:1;P:(14,0);RX:1),
(N:'RST';X:1;P:(27,0);RX:0),
{216-223}
(N:'RET';X:1;P:(1,0);RX:0),
(N:'err';X:0;P:(0,0);RX:0),
(N:'JP';X:2;P:(1,13);RX:2),
(N:'IN';X:2;P:(7,33);RX:1),
(N:'CALL';X:2;P:(1,13);RX:2),
(N:'err';X:0;P:(0,0);RX:0),
(N:'SBC';X:2;P:(7,14);RX:1),
(N:'RST';X:1;P:(28,0);RX:0),
{224-231}
(N:'RET';X:1;P:(17,0);RX:0),
(N:'POP';X:1;P:(10,0);RX:0),
(N:'JP';X:2;P:(17,13);RX:2),
(N:'EX';X:2;P:(34,10);RX:0),
(N:'CALL';X:2;P:(17,13);RX:2),
(N:'PUSH';X:1;P:(10,0);RX:0),
(N:'AND';X:1;P:(14,0);RX:1),
(N:'RST';X:1;P:(29,0);RX:0),
{232-239}
(N:'RET';X:1;P:(18,0);RX:0),
(N:'JP';X:0;P:(6,0);RX:0),
(N:'JP';X:0;P:(18,13);RX:2),
(N:'EX';X:2;P:(9,10);RX:0),
(N:'CALL';X:2;P:(18,13);RX:2),
(N:'err';X:0;P:(0,0);RX:0),
(N:'XOR';X:1;P:(14,0);RX:1),
(N:'RST';X:1;P:(30,0);RX:0),
{240-247}
(N:'RET';X:1;P:(19,0);RX:0),
(N:'POP';X:1;P:(11,0);RX:0),
(N:'JP';X:2;P:(19,13);RX:2),
(N:'DI';X:0;P:(0,0);RX:0),
(N:'CALL';X:2;P:(19,13);RX:2),
(N:'PUSH';X:1;P:(11,0);RX:0),
(N:'OR';X:1;P:(14,0);RX:1),
(N:'RST';X:1;P:(31,0);RX:0),
{248-255}
(N:'RET';X:1;P:(20,0);RX:0),
(N:'LD';X:2;P:(12,10);RX:0),
(N:'JP';X:2;P:(20,13);RX:2),
(N:'EI';X:0;P:(0,0);RX:0),
(N:'CALL';X:2;P:(20,13);RX:2),
(N:'err';X:0;P:(0,0);RX:0),
(N:'CP';X:1;P:(14,0);RX:1),
(N:'RST';X:1;P:(32,0);RX:0)
);
ReNr:Array[0..34] of
      string[4]=
(
{ 0}'B',
{ 1}'C',
{ 2}'D',
{ 3}'E',
{ 4}'H',
{ 5}'L',
{ 6}'(HL)',
{ 7}'A',
{ 8}'BC',
{ 9}'DE',
{10}'HL',
{11}'AF',
{12}'SP',
{13}'nn',
{14}'n',
{15}'Z',
{16}'NZ',
{17}'PO',
{18}'PE',
{19}'P',
{20}'M',
{21}'NC',
{22}'(BC)',
{23}'(DE)',
{23}'(nn)',
'#0','#8','#10','#18','#20',
'#28','#30','#38','(n)','(SP)'
);


Function WStr(x:word):string;
var qwstr:string;
begin
     str (x,qwstr);
     wstr:=qwstr;
end;
Procedure Init;
Begin
End;

Function Disass1b(b1,b2,b3:byte;var cnt:integer):String;
Var ds:string;
parc:integer;
Begin
     ds:=tab[b1].N;
     cnt:=tab[b1].RX+1;
     if tab[b1].x>0 then
     for parc:=0 to tab[b1].x-1 do
     begin
         case parc of
              0: ds:=ds+' ';
              1: ds:=ds+',';
         else ds:=ds+',';
         end;


if renr[tab[b1].p[parc]]='n' then ds:=ds+wstr(b2) else
if renr[tab[b1].p[parc]]='nn' then ds:=ds+wstr(b2+256*b3) else
if renr[tab[b1].p[parc]]='(n)' then ds:=ds+'('+wstr(b2)+')' else
if renr[tab[b1].p[parc]]='(nn)' then ds:=ds+'('+wstr(b2+256*b3)+')' else

ds:=ds+renr[tab[b1].p[parc]];

     end;
     disass1b:=ds;
End;
Procedure Ass(Instr:String;Adr:Word);
Begin
End;
Procedure EditIt;
Begin
End;
