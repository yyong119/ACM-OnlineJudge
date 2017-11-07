var
        s,y,tmp,ans:int64;
        mid,left,right,i,n,m,max,min:longint;
        c,a,w,v,l,r:array [0..222222] of longint;
 
procedure work(t:longint);
var
        i:longint;
        count,tot:int64;
begin
        fillchar(a,sizeof(a),0);
        fillchar(c,sizeof(c),0);
        for i:=1 to n do
        begin
                if w[i]>=t then begin
                        a[i]:=a[i-1]+v[i];
                        c[i]:=c[i-1]+1;
                        end
                else begin
                        a[i]:=a[i-1];
                        c[i]:=c[i-1];
                        end;
        end;
        y:=0;
        for i:=1 to m do
        begin
                count:=c[r[i]]-c[l[i]-1];
                tot:=a[r[i]]-a[l[i]-1];
                y:=y+count*tot;
                end;
end;
 
begin
        readln(n,m,s);
        max:=0;
        min:=maxlongint-1;
        for i:=1 to n do
        begin
                readln(w[i],v[i]);
                if w[i]>max then max:=w[i];
                if w[i]<min then min:=w[i];
 
        end;
        for i:=1 to m do
        begin
                readln(l[i],r[i]);
        end;
        left:=min-1;
        right:=max+1;
        ans:=maxlongint*1000000;
        while left<right do
        begin
                mid:=(left+right) div 2;
                work(mid);
                tmp:=s-y;
 
                if abs(tmp)<ans then ans:=abs(tmp);
                if ans=0 then break;
                if s>y then right:=mid else left:=mid+1;
        end;
        writeln(ans);
end.