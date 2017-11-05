var
        map:array[1..100,1..100] of longint;
        i,j,k,n,total,lined,ans:longint;
        data:array[1..10000,1..3] of longint;
        father:array[1..100] of longint;
function getfather(u:longint):longint;
begin
        if father[u]<>u then father[u]:=getfather(father[u]);
        exit(father[u]);
end;
procedure union(u,v:longint);
var x,y:longint;
begin
        x:=getfather(u); y:=getfather(v);
        father[x]:=y;
end;
procedure qsort(l,r:longint);
var i,j,mid:longint;
        temp:array[1..3] of longint;
begin
        i:=l; j:=r; mid:=data[(l+r) div 2,3];
        repeat
                while data[i,3]<mid do inc(i);
                while data[j,3]>mid do dec(j);
                if not(i>j) then
                begin
                        temp:=data[i]; data[i]:=data[j]; data[j]:=temp;
                        inc(i); dec(j);
                end;
        until i>j;
        if i<r then qsort(i,r); if j>l then qsort(l,j);
end;
begin
        readln(n); lined:=1;
        for i:=1 to n do father[i]:=i;
        for i:=1 to n do
        begin
                for j:=1 to n do
                begin
                        read(map[i,j]);
                        if j>i then
                        begin
                                inc(total);
                                data[total,1]:=i;
                                data[total,2]:=j;
                                data[total,3]:=map[i,j];
                        end;
                end;
                readln;
        end;
        qsort(1,total);
        while lined<n do
        begin
                inc(k);
                if getfather(data[k,1])<>getfather(data[k,2]) then
                begin
                        union(data[k,1],data[k,2]);
                        inc(ans,data[k,3]);
                        inc(lined);
                end;
        end;
        writeln(ans);
end.