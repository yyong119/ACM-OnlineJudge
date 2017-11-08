var
    n,m,i,j,k,len,min:longint;
    a,sum:array[0..100] of longint;
    f:array[0..100,0..100] of longint;
begin
    readln(n);
    for i:=1 to n do begin read(a[i]); sum[i]:=sum[i-1]+a[i]; end;
    for len:=2 to n do
        for i:=1 to n-len+1 do
        begin
            j:=i+len-1; min:=maxlongint;
            for k:=i to j-1 do
            if f[i,k]+f[k+1,j]+sum[j]-sum[i-1]<min then
                min:=f[i,k]+f[k+1,j]+sum[j]-sum[i-1];
            f[i,j]:=min;
        end;
    writeln(f[1,n]);
end.