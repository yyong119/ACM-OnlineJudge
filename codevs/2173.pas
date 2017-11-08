Type point=record
      x,y,min,c1,c2:longint;
      end;
Var a:array[1..100000]of longint;
   ans:array[1..200000]of longint;
   tree:array[1..200000]of point;
   m,n,i,j,k,all:longint;
function min(a,b:longint):longint;
   begin if a<b then exit(a)else exit(b)end;
procedure build(x,y:longint);
   var mid,count:longint;
   begin
   inc(all);count:=all;
   tree[count].x:=x;
   tree[count].y:=y;
   if y=x
      then begin
      tree[count].min:=a[x];
      exit;
      end;
   mid:=(x+y)div 2;
   tree[count].min:=maxlongint;
   if mid>=x
      then begin
      tree[count].c1:=all+1;
      build(x,mid);
      tree[count].min:=tree[tree[count].c1].min;
      end;
   if mid+1<=y
      then begin
      tree[count].c2:=all+1;
      build(mid+1,y);
      tree[count].min:=min(tree[count].min,tree[tree[count].c2].min);
      end;
   end;
function find(x,y,count:longint):longint;
   var mid,ans1,ans2:longint;
   begin
   if (x=tree[count].x)and(y=tree[count].y) then exit(tree[count].min);
   mid:=(tree[count].x+tree[count].y)div 2;
   if (tree[count].x<=x)and(y<=mid) then exit(find(x,y,tree[count].c1));
   if (mid+1<=x)and(y<=tree[count].y) then exit(find(x,y,tree[count].c2));
   ans1:=find(x,mid,tree[count].c1);
   ans2:=find(mid+1,y,tree[count].c2);
   exit(min(ans1,ans2));
   end;
Begin
readln(m,n);
for i:=1 to m do
   read(a[i]);
build(1,m);
for i:=1 to n do
   begin
   readln(j,k);
   ans[i]:=find(j,k,1);
   end;
write(ans[1]);
for i:=2 to n do
   write(' ',ans[i]);
writeln;
End.