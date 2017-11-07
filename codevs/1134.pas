var
        n,m,i,j,k,l,x,y,ans:longint;
        xy:array[1..10000,1..2] of longint;
        cc:array[1..10000,1..2] of longint;
begin
        readln(n); ans:=-1;
        for i:=1 to n do readln(xy[i,1],xy[i,2],cc[i,1],cc[i,2]);
        readln(x,y);
        for i:=1 to n do
                if (x>=xy[i,1])and(x<=xy[i,1]+cc[i,1])and(y>=xy[i,2])and(y<=xy[i,2]+cc[i,2]) then
                        ans:=i;
        writeln(ans);
end.