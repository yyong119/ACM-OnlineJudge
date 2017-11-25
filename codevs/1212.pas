var a,b:longint;
function gys(x,y:longint):longint;
var r:longint;
begin
  if x<y then begin 
    r:=x;x:=y;y:=r;
  end;
  repeat
    r:=y;
    y:=x mod y ;
    x:=r;
  until y=0;
  gys:=x;
end;
begin
    readln(a,b);
    writeln(gys(a,b));
end.