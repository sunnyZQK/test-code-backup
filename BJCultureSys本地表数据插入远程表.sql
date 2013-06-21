USE [BJCultureSys]
GO
/****** Object:  StoredProcedure [dbo].[SP_Service_Bar_TerminalInfo]    Script Date: 06/19/2013 17:23:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_Service_Bar_TerminalInfo]
AS 
  BEGIN

    SET NOCOUNT ON;   --不返回计数 该设置由于大量减少了网络流量，因此可显著提高性能。
    
	-- 将dbo.Bar_TerminalInfo数据插入临时表#tmp
    SELECT * INTO #tmp FROM dbo.Bar_TerminalInfo
    --从临时表里跟据BarCode, HostIP去重取出记录插入链接服务的Bar_TerminalInfotmp
    INSERT  INTO BJTODB.BJCultureSys.dbo.Bar_TerminalInfotmp
            (BarCode, HostIP, HostMac, HostName, HostNum, IsCamra, CurrentStatus, LastUpdate, ProvinceID, CityID, DistrictID, ClientVersion, BarCusName, BarCusCertNO, BarCusCertType, BarUserNO, BarCusLoginTime)
    SELECT  BarCode, HostIP, HostMac, HostName, HostNum, IsCamra, CurrentStatus, LastUpdate, ProvinceID, CityID, DistrictID, ClientVersion, BarCusName, BarCusCertNO, BarCusCertType, BarUserNO, BarCusLoginTime
    FROM    #tmp
    WHERE   ID IN ( 
      SELECT MAX(ID) AS ID FROM #tmp GROUP BY BarCode, HostIP 
            )
            
    --在Bar_TerminalInfo表里删除 #tmp相同的字段
    DELETE  FROM Bar_TerminalInfo
    WHERE  ID IN (SELECT ID  FROM  #tmp )	
    --删除临时表
    DROP TABLE #tmp	
  END
