var
    n:longint;
function digui(a:longint):longint;
begin
    if a>=0 then digui:=5
    else digui:=digui(a+1)+digui(a+2)+1;
end;
begin
    readln(n);
    writeln(digui(n));
end.