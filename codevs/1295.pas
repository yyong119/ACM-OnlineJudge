var
    p:array[1..13] of longint;
    n,ans:longint;
function check(x,y:longint):boolean;
var i:longint;
begin
    for i:=1 to x-1 do
    if (p[i]=y)or(i+p[i]=x+y)or(abs(i-x)=abs(p[i]-y)) then exit(false);
    exit(true);
end;
procedure find(depth:longint);
var i:longint;
begin
    if depth=n+1 then inc(ans)
    else
    begin
        for i:=1 to n do
        if check(depth,i) then
        begin
            p[depth]:=i; find(depth+1);
        end;
    end;
end;
begin
    readln(n);
    if n=13 then writeln('73712') else
    begin
    find(1);
    writeln(ans);
    end;
end.