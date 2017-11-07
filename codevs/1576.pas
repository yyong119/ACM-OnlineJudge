var
        a,b:array[1..5000] of longint;
        n,m,i,j,k,l:longint;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                b[i]:=1;
        end;
        for i:=2 to n do
        begin
                l:=0;
                for j:=1 to i-1 do
                        if (a[j]<a[i])and(b[j]>l) then l:=b[j];
                if l+1>b[i] then b[i]:=l+1;
        end;
        for i:=1 to n do if b[i]>k then k:=b[i];
        writeln(k);
end.