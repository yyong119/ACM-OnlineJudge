var
        n,k,p,ans,color,cost,i:longint;
        a,b:array[0..100]of longint;
begin
        readln(n,k,p);
        ans:=0;
        for i:=1 to n do
        begin
                readln(color,cost);
                inc(b[color]);
                if cost<=p then
                begin
                        a:=b;
                        inc(ans,a[color]-1);
                end else inc(ans,a[color]);
        end;
        writeln(ans);
end.