var
    l,r,i,ans:longint;
function check(k:longint):boolean;
var i:longint;
begin
    for i:=2 to trunc(sqrt(k)) do
        if k mod i=0 then exit(false);
    exit(true);
end;
begin
    readln(l,r); if l<2 then l:=2;
    for i:=l to r do if check(i) then inc(ans);
    writeln(ans);
end.