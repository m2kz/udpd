template <typename T, typename S>
class ProcessError {
    private:
        S errorCode = {};
    public:
        ProcessError(S errorCode) : errorCode(errorCode) {}
};