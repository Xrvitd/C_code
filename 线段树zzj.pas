var
  d,lr,rr,n,m,x:longint;
  i:longint;
  delta,key:array[0..800000] of int64;

  procedure update(now:longint);
  begin
    key[now]:=key[now shl 1]+key[(now shl 1)+1];
  end;

  procedure build(now,l,r:longint);
  var
    mid:longint;
  begin
    if l=r then
    begin
      read(key[now]);
      exit;
    end;
    mid:=(l+r) shr 1;
    build(now shl 1,l,mid);
    build((now shl 1)+1,mid+1,r);
    update(now);
  end;

  procedure pushdown(now,l,r,mid:longint);
  begin
    if delta[now]<>0 then
    begin
      key[now shl 1]:=key[now shl 1]+delta[now]*(mid-l+1);
      delta[now shl 1]:=delta[now shl 1]+delta[now];
      key[(now shl 1)+1]:=key[(now shl 1)+1]+delta[now]*(r-mid);
      delta[(now shl 1)+1]:=delta[(now shl 1)+1]+delta[now];
      delta[now]:=0;
    end;
  end;

  procedure change(now,l,r,lr,rr,v:longint);
  var
    mid:longint;
  begin
    if (lr<=l) and (r<=rr) then
    begin
      key[now]:=key[now]+(r-l+1)*v;
      delta[now]:=delta[now]+v;
      exit;
    end;
    mid:=(l+r) shr 1;
    pushdown(now,l,r,mid);
    if lr<=mid then change((now shl 1),l,mid,lr,rr,v);
    if rr>mid then change((now shl 1)+1,mid+1,r,lr,rr,v);
    update(now);
  end;

  function query(now,l,r,lr,rr:longint):int64;
  var
    mid:longint;
    ans:int64;
  begin
    if (lr<=l) and (r<=rr) then exit(key[now]);
    mid:=(l+r) shr 1;
    pushdown(now,l,r,mid);
    ans:=0;
    if lr<=mid then
      ans:=ans+query(now shl 1,l,mid,lr,rr);
    if rr>mid then
      ans:=ans+query((now shl 1)+1,mid+1,r,lr,rr);
    exit(ans);
  end;
begin
  read(n);
  build(1,1,n);
  read(m);
  for i:=1 to m do
  begin
    read(d,lr,rr);
    if d=1 then
    begin
      read(x);
      change(1,1,n,lr,rr,x);
    end
    else
    begin
      writeln(query(1,1,n,lr,rr));
    end;
  end;
end.