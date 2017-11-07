var
        a:array[1..16,1..2] of longint;
        n,i:longint;
procedure find1(x:longint);
begin
        write(x,' ');
        if a[x,1]<>0 then find1(a[x,1]);
        if a[x,2]<>0 then find1(a[x,2]);
end;
procedure find2(x:longint);
begin
        if a[x,1]<>0 then find2(a[x,1]);
        write(x,' ');
        if a[x,2]<>0 then find2(a[x,2]);
end;
procedure find3(x:longint);
begin
        if a[x,1]<>0 then find3(a[x,1]);
        if a[x,2]<>0 then find3(a[x,2]);
        write(x,' ');
end;
begin
        readln(n);
        for i:=1 to n do read(a[i,1],a[i,2]);
        find1(1); writeln;
        find2(1); writeln;
        find3(1); writeln;
end.