program p1200;
var
 x,y,a,b,d:int64;
procedure gcd(a,b:int64);
var
 t:int64;
begin
 if a mod b=0 then begin x:=0; y:=1; end
  else begin gcd(b,a mod b); t:=x; x:=y; y:=t-(a div b)*y; end;
end;
begin
 readln(a,b);
 d:=b;
 gcd(a,b);
 writeln((x mod d+d)mod d);
end.