var m,n,x1,x2,y1,y2:longint;
i,j,k,x,y:longint;
map:array[-2..52,-2..52] of extended;
begin
    readln(m,n,x1,y1,x2,y2);
    map[x1,y1]:=1;
    for i:=x1+1 to x2 do
    for j:=1 to m do
        map[i,j]:=map[i-1,j-2]+map[i-1,j+2]+map[i-2,j-1]+map[i-2,j+1];
    writeln(map[x2,y2]:0:0);
end.