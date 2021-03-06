//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// Copyright 2013 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//
package com.automatak.dnp3;

/**
*/
public enum EventCounterResponse
{
  Group22Var1(0),
  Group22Var2(1),
  Group22Var5(2),
  Group22Var6(3);

  private final int id;

  private EventCounterResponse(int id)
  {
    this.id = id;
  }

  public int toType()
  {
    return id;
  }

  public static EventCounterResponse fromType(int arg)
  {
    switch(arg)
    {
      case(0):
        return Group22Var1;
      case(1):
        return Group22Var2;
      case(2):
        return Group22Var5;
      case(3):
        return Group22Var6;
    }
    return Group22Var6;
  }
}
