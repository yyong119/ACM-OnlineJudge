var i,j,n,k,m:longint;
    a:array [1..100,1..100] of longint;
function max(w,e:longint):longint;
begin if w>e then exit(w); exit(e); end;
begin
    readln(n);
    for i:=1 to n do 
        for j:=1 to i do read(a[i,j]);
    for i:=n-1 downto 1 do
        for j:=1 to j do 
        a[i,j]:=a[i,j]+max(a[i+1,j],a[i+1,j+1]);
    writeln(a[1,1]);
end.