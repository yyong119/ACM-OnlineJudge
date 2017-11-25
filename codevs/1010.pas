const dx:array[1..8] of longint=(1,2,2,1,-1,-2,-2,-1);
      dy:array[1..8] of longint=(-2,-1,1,2,2,1,-1,-2);
var
    a:array[-2..17,-2..17] of longint;
    ex,ey,mx,my,i,j,k,l:longint;
begin
    readln(ex,ey,mx,my);
    a[mx,my]:=-1; a[0,0]:=1;
    for i:=1 to 8 do a[mx+dx[i],my+dy[i]]:=-1;
    for i:=0 to ex do
        for j:=0 to ey do
        begin
            if (a[i,j]=-1)or(i=0)and(j=0) then continue;
            if (a[i-1,j]<>-1)and(a[i,j-1]<>-1) then a[i,j]:=a[i-1,j]+a[i,j-1]
                else if (a[i-1,j]<>-1)and(a[i,j-1]=-1) then a[i,j]:=a[i-1,j]
                else a[i,j]:=a[i,j-1];
        end;
    writeln(a[ex,ey]);
end.