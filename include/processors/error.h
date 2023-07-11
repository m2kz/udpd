template <typename T>
class ProcessError {
    private:
        const typename T::error_t errorVal = {};
    public:
        ProcessError() = default;
        ProcessError(typename T::error_t errorVal) : errorVal(errorVal) {};
};