class RadarServiceProxy {
public:


/*
* ctor signature is not given as it is not of interest to the user.
*/
class HandleType {
/**
* \brief Two ServiceHandles are considered equal if they represent the
same service instance.
*
* \param other
*
* \return
*/
inline bool operator==(const HandleType &other) const;
const ara::com::InstanceIdentifier &GetInstanceId() const;
};


/**
* StartFindService does not need an explicit version parameter as this
is internally available in ProxyClass
* That means only compatible services are returned.
*
* \param handler this handler gets called any time the service
availability of the services matching the given
* instance criteria changes. If you use this variant of FindService,
the Communication Management has to
* continuously monitor the availability of the services and call the
handler on any change.
*
* \param instance which instance of the service type defined by T shall
be searched/found. Wildcards may be given.
* Default value is wildcard.
*
* \return a handle for this search/find request, which shall be used to
stop the availability monitoring and related
* firing of the given handler. (\see StopFindService())
**/
static ara::com::FindServiceHandle StartFindService(
ara::com::FindServiceHandler<RadarServiceProxy::HandleType> handler,
ara::com::InstanceIdentifier instance =
ara::com::InstanceIdentifier::Any);

/**
* Method to stop finding service request (see above)
*/
static void StopFindService(ara::com::FindServiceHandle handle);


/**
* Opposed to StartFindService(handler, instance) this version is a "one-
shot" find request, which is
* - synchronous, i.e. it returns after the find has been done and a
result list of matching service instances is
* available. (list may be empty, if no matching service instances
currently exist)
* - does reflect the availability at the time of the method call. No
further (background) checks of availability
* are done.
*

* \param instance which instance of the service type defined by T shall
be searched/found. Wildcards may be given.
* Default value is wildcard.
*/
static ara::com::ServiceHandleContainer<RadarServiceProxy::HandleType>
FindService(
ara::com::InstanceIdentifier instance =
ara::com::InstanceIdentifier::Any);

/**
* \brief The proxy can only be created using a specific handle which
identifies a service.
*
* This handle can be a known value which is defined at deployment or it
can be obtained using the ProxyClass::FindService method.
*
* \param handle The identification of the service the proxy should
represent.
*/
explicit RadarServiceProxy(HandleType &handle);

/**
* \brief Public member for the BrakeEvent
*/
events::BrakeEvent BrakeEvent;

/**
* \brief Public Field for UpdateRate
*/
fields::UpdateRate UpdateRate;

/**
* \brief Public member for the Calibrate method
*/
methods::Calibrate Calibrate;

**
* \brief Public member for the Adjust method
*/
methods::Adjust Adjust;
};