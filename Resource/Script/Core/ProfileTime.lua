ProfileTime=
{
    mSample,
    mStartTime,
    mEndTime,
    mUseTime,
}


function ProfileTime:BeginSample(varSample)
    mSample=varSample
    self.mStartTime = os.clock();
end


function ProfileTime:EndSample()
    self.mEndTime = os.clock();
    self.mUseTime = self.mEndTime - self.mStartTime;
    print("ProfileTime UseTime:" .. self.mUseTime)
end

return ProfileTime