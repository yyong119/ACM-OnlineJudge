type list=record x,n:longint;end;  
var n,i,j,o:longint;  
    e:array[0..6000]of list;  
    value,fa,k:array[0..6000]of longint;  
        v:array[0..6000]of boolean;  
        f,g:array[0..6000]of longint;  
function max(a,b:longint):longint;  
  begin
    if a>b then exit(a) else exit(b);  
  end;  
procedure add(a,b:longint);  
  begin
    inc(o);  
    e[o].x:=b;  
    e[o].n:=k[a];  
    k[a]:=o;  
  end;  
procedure init;  
var i,a,b:longint;  
begin
    readln(n);  
    for i:=1 to n do
      begin
        readln(value[i]);  
      end;  
    for i:=1 to n-1 do
      begin
        readln(a,b);  
        add(b,a);  
        v[a]:=true;  
      end;  
 end;  
procedure dp(x:longint);  
  var t:longint;  
  begin
    t:=k[x];  
    if (t=0) then begin f[x]:=value[x];exit;end;  
    while t<>0 do begin dp(e[t].x);t:=e[t].n;end;  
    t:=k[x];  
    while t<>0 do
      begin
        f[x]:=f[x]+g[e[t].x];  
        g[x]:=g[x]+max(g[e[t].x],f[e[t].x]);  
        t:=e[t].n;  
      end;  
    f[x]:=f[x]+value[x];  
  end;  
procedure work;  
  var i:longint;  
  begin
    for i:=1 to n do
      if not v[i] then break;  
    dp(i);  
        writeln(max(f[i],g[i]));  
  end;  
begin
  init;  
  work;  
end. 