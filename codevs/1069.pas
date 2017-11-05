type point=array[1..3]of longint;  
var n,m,i,x,y,ans:longint;  
   c:array[0..100000]of point;  
   fa:array[0..40000]of longint;  
procedure qsort(l,r:longint);  
var i,j,x:longint;  
    y:point;  
begin
    i:=l;j:=r;x:=c[(i+j)div 2,3];  
    repeat
      while c[i,3]>x do inc(i); while x>c[j,3] do dec(j);  
      if i<=j then
      begin y:=c[i];c[i]:=c[j];c[j]:=y; inc(i);dec(j); end;  
    until i>j;  
    if l<j then qsort(l,j); if i<r then qsort(i,r);  
end;  
function find(x:longint):longint;  
begin if x<>fa[x] then fa[x]:=find(fa[x]); exit(fa[x]); end;  
begin
    readln(n,m);  
    for i:=1 to m do readln(c[i,1],c[i,2],c[i,3]);  
    qsort(1,m);  
    for i:=1 to n*2 do fa[i]:=i;  
    for i:=1 to m+1 do
    begin
        x:=find(c[i,1]); y:=find(c[i,2]);  
        if x=y then break;  
        fa[x]:=fa[find(c[i,2]+n)]; fa[y]:=fa[find(c[i,1]+n)];  
   end;  
   writeln(c[i,3]);  
end.  