var
        n,total,i,mid,temp:longint;
        a:array[1..100] of longint;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                inc(total,a[i]);
        end;
        mid:=total div n;  total:=0;
        for i:=1 to n-1 do
        begin
                if a[i]>mid then
                begin
                        temp:=a[i]-mid;
                        a[i]:=mid;
                        inc(a[i+1],temp);
                        inc(total);
                end;
                if a[i]<mid then
                begin
                        temp:=mid-a[i];
                        a[i]:=mid;
                        dec(a[i+1],temp);
                        inc(total);
                end;
                if a[i]=mid then continue;
        end;
        writeln(total);
end.