var
    a:array[1..50000] of longint;
    n,m,i,j,k,min,minnum,sum:longint;
begin
    readln(n);
    for i:=1 to n do
    begin
        read(m);  min:=maxlongint;
        for j:=1 to m do read(a[j]); readln;
        for j:=49 downto 0 do
        begin
            sum:=0;
            for k:=1 to m do inc(sum,abs(a[k]-j));
            if sum<=min then
            begin
                min:=sum;
                minnum:=j;
            end;
        end;
        writeln(minnum,' ',min);
    end;
end.