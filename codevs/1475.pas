var
    s:string; c:char;
    i,j,l,sum,len:longint;
function power (x,y:longint):longint;
var i:longint;
begin
    power:=1;
    if y=0 then exit;
    for i:=1 to y do power:=power*x;
end;
begin
    read(c);
    while c<>' ' do
    begin
        s:=s+c;
        read(c);
    end;
    read(l); len:=length(s);
    for i:=len downto 1 do
    begin
        if ord(s[i])-ord('0')<10 then inc(sum,(ord(s[i])-ord('0'))*power(l,len-i))
        else
        begin
            case s[i] of
                'A':j:=10;
                'B':j:=11;
                'C':j:=12;
                'D':j:=13;
                'E':j:=14;
                'F':j:=15;
            end;
            inc(sum,j*power(l,len-i));
        end;
    end;
    writeln(sum);
end.