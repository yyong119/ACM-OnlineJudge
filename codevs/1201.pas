var
    n,i,x:longint;
    max,min:int64;
begin
    max:=-maxlongint; min:=maxlongint;
    readln(n);
    for i:=1 to n do
    begin
        read(x);
        if x>max then max:=x;
        if x<min then min:=x;
    end;
    writeln(min,' ',max);
end.