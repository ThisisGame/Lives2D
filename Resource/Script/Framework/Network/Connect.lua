local Connect=class()

function Connect:ctor()
    self.mConnectID=nil,
    self.mHost=nil,
    self.mPort=nil,
    self.mCallbackReceiver=nil,
    self.mReceiveConnectAcceptedListener=nil,
    self.mReceiveNewPackListener=nil,
    self.mUDPSocket=nil,
end


function Connect:Connect(varConnectID,varHost,varPort,this,varReceiveConnectAcceptedListener,varReceiveNewPackListener)
    self.mConnectID=varConnectID
    self.mHost=varHost
    self.mPort=varPort
    self.mCallbackReceiver=this
    self.mReceiveConnectAcceptedListener=varReceiveConnectAcceptedListener
    self.mReceiveNewPackListener=varReceiveNewPackListener

    self.mUDPSocket=UDPSocket:new()
    self.mUDPSocket:SetReceiveConnectAccepted(Wrap(self,self.ReceiveConnectAccepted))
    self.mUDPSocket:SetReceiveNewPackListener(Wrap(self,self.ReceiveNewPackListener))
end

function Connect:ReceiveConnectAccepted(varSocketID)
	print("Connect ReceiveConnectAccepted")
    self.mReceiveConnectAcceptedListener(self.mCallbackReceiver,self.mConnectID,varSocketID)
end


function Connect:ReceiveNewPackListener(varSocketID,varJson)
    self.mReceiveNewPackListener(self.mCallbackReceiver,self.mConnectID,varSocketID,varJson)
end

function Connect:Update()
    if self.mUDPSocket~=nil then
        self.mUDPSocket:Update()
    end
end

return Connect
