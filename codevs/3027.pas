var
        a,b,f:array[1..1000]of longint;
        i,j,k,n,ans:longint;
function max(a,b:longint):longint;
begin
        if a>b then exit(a); exit(b);
end;
procedure qsort(l,r:longint);
var i,j,mid,temp:longint;
begin
        i:=l; j:=r; mid:=b[(l+r) div 2];
        repeat
                while b[i]<mid do inc(i);
                while b[j]>mid do dec(j);
                if not(i>j) then
                begin
                        temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
                        temp:=b[i]; b[i]:=b[j]; b[j]:=temp;
                        temp:=f[i]; f[i]:=f[j]; f[j]:=temp;
                        inc(i); dec(j);
                end;
        until i>j;
        if i<r then qsort(i,r); if j>l then qsort(l,j);
end;
Begin
        readln(n);
        for i:=1to n do
        read(a[i],b[i],f[i]);
        qsort(1,n);
        for i:=2to n do
        begin
                k:=0;
                for j:=1to i-1 do
                        if b[j]<=a[i] then k:=max(k,f[j]);
                f[i]:=k+f[i];
        end;
        for i:=1 to n do ans:=max(ans,f[i]);
        writeln(ans);
end.