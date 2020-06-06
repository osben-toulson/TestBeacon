# TestBeacon
Example Code For Unreal Test Beacon Implemtation<br>
<sup><i>Tested on UE4.24.3</i></sup>

This UE4 Plugin implements the Test Beacon from the "Online Beacon Example" section from the [official documentation](https://docs.unrealengine.com/en-US/Gameplay/Networking/OnlineBeacons/index.html).
The goal is to showcase the TestBeacon with minimal frills as a code example.

# How To Use
<i>UE4 Plugin familiarity assumed</i><br>
* Create a project and clone this repository into Plugins folder (You may need to create the Plugins folder)
* Append to DefaultEngine.ini file:<br>
```
[/Script/Engine.Engine]
!NetDriverDefinitions=ClearArray
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="/Script/OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")
+NetDriverDefinitions=(DefName="BeaconNetDriver",DriverClassName="/Script/OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")

[/Script/TestBeacon.TestBeacon]
!NetDriverDefinitions=ClearArray
+NetDriverDefinitions=(DefName="BeaconNetDriver",DriverClassName="/Script/OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")
```
* Go to TestBeacon C++ Classes -> TestBeacon -> Public in the Content Browser
* Drag the TestBeaconActor onto the level
* Set the "Number of Players" to 2 (Default multiplayer options should be fine)
* Play the level in the editor
<br>
The Output Log will show the Ping / Pong loop with the LogBeacon tag.<br><br>
Credit:<br>
https://forums.unrealengine.com/community/community-content-tools-and-tutorials/1355434-onlinebeacons-tutorial-with-blueprint-access
