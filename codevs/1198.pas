Type
        gjd=record
                len:longint;
                d:array[0..2000] of longint;
        end;
Var
        n,i:longint;
        a,b:array[0..10002] of longint;
        now,max,q:gjd;
Procedure swap(var p,q:longint);
var y:longint;
begin
        y:=p;
        p:=q;
        q:=y;
end;
Procedure qsort(l,r:longint);
var i,j,x:longint;
begin
        i:=l;j:=r;x:=a[(l+r) div 2]*b[(l+r) div 2];
        repeat
                while a[i]*b[i]<x do inc(i);
                while a[j]*b[j]>x do dec(j);
                if i<=j then
                begin
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);
                        inc(i); dec(j);
                end;
        until i>j;
        if l<j then qsort(l,j); if i<r then qsort(i,r);
end;
Procedure print(P:gjd);
var i:longint;
begin
        for i:=p.len downto 1 do
        begin
                if i<>p.len then
                begin
                        if p.d[i]<10 then write(0);
                        if p.d[i]<100 then write(0);
                        if p.d[i]<1000 then write(0);
                end;
                write(p.d[i]);
        end;
end;
Function more(p,q:gjd):boolean;
var i:longint;
begin
        if p.len>q.len then exit(true);
        for i:=p.len downto 1 do
        begin
                if p.d[i]>q.d[i] then exit(true);
                if p.d[i]<q.d[i] then exit(false);
        end;
        exit(false);
end;
Function cheng(p:gjd;q:longint):gjd;
var i,jw:longint;
begin
        cheng:=p;
        jw:=0;
        for i:=1 to cheng.len do
        begin
                cheng.d[i]:=cheng.d[i]*q+jw;
                jw:=cheng.d[i] div 10000;
                cheng.d[i]:=cheng.d[i] mod 10000;
        end;
        while jw>0 do
        begin
                inc(cheng.len);
                cheng.d[cheng.len]:=jw;
                jw:=cheng.d[cheng.len] div 10000;
                cheng.d[cheng.len]:=cheng.d[cheng.len] mod 10000;
        end;
        while (cheng.len>1) and (cheng.d[cheng.len]=0) do dec(cheng.len);
end;
Function divide(P:gjd;q:longint):gjd;
var ans:gjd; i,jw:longint;
begin
        ans:=p; jw:=0;
        for i:=ans.len downto 1 do
        begin
                ans.d[i]:=(ans.d[i]+jw*10000) div q;
                jw:=(p.d[i]+jw*10000)-ans.d[i]*q;
        end;
        while (ans.len>1) and (ans.d[ans.len]=0) do dec(ans.len);
        exit(ans);
end;
begin
        readln(n);
        for i:=0 to n do readln(a[i],b[i]);
        qsort(1,n);
        now.len:=1; now.d[1]:=a[0]; max.len:=1; max.d[1]:=0;
        for i:=1 to n do
        begin
                q:=divide(now,b[i]);
                if more(q,max) then max:=q;
                now:=cheng(now,a[i]);
        end;
        print(max);
end.